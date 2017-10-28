#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* mqtt_server = MQTT_BROKER;

WiFiClient espClient;
PubSubClient client(espClient);

char _mqtt_msg[75];

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.println("] ");

  // for (int i = 0; i < length; i++) {
  //   Serial.print((char)payload[i]);
  // }
  // Serial.println();

  int value = getDomoticzValue(payload);

  if (value == 0){
    Serial.println("Apagar");
    rpiApagar();
  }
  else if (value == 1){
    Serial.println("Encender");
    rpiEncender();
  }
  else{
    Serial.println("El mensaje no es para nosotros");
  }
}

// TODO reconnect que no bloquee
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = APP_NAME;
    clientId += "-" + String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      // TODO mandar estado o heartbeat al conectar
      //client.publish(DOMOTICZ_IN_TOPIC, "hello world");
      // ... and resubscribe
      client.subscribe(DOMOTICZ_OUT_TOPIC);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void mqttSetup() {
  randomSeed(micros());
  client.setServer(mqtt_server, MQTT_PORT);
  client.setCallback(mqttCallback);
}

void mqttLoop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  mqttHeartbeat();

}

void mqttHeartbeat(){
  static unsigned long mqtt_heartbeat_time = 0;
  if (millis() > mqtt_heartbeat_time) {
    mqtt_heartbeat_time = millis() + HEARTBEAT_FREC;
    mqttSendState();
  }
}

void mqttSendState(){
  snprintf (_mqtt_msg, 75, "{ \"idx\" : %d, \"nvalue\" : %d, \"svalue\" : \"0\" }", DOMOTICZ_IDX, getEstadoRpi());
  // snprintf (_mqtt_msg, 75, "{\"command\" : \"addlogmessage\", \"message\" : \"Hola\" }");
  Serial.print("Enviando estado: ");
  Serial.println(_mqtt_msg);
  client.publish(DOMOTICZ_IN_TOPIC, _mqtt_msg);
}

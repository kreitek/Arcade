#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* mqtt_server = MQTT_BROKER;

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char _mqtt_msg[75];
int value = 0;

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.println("!!!!!!!!!!!!!!!ALGO!!!!!!!!!!!!!!!!!");
  Serial.println(length);
  return;

  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    Serial.println("Encender");
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
  } else {
    Serial.println("Apagar");
  }

}

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

  long now = millis();
  if (now - lastMsg > 15000) {
    lastMsg = now;
    ++value;
    static bool onoff = false;
    onoff = !onoff;
    // snprintf (_mqtt_msg, 75, "hello world #%ld", value);
    // snprintf (_mqtt_msg, 75, "{ \"idx\" : %d, \"nvalue\" : %d, \"svalue\" : \"0\" }", DOMOTICZ_IDX, onoff? 1:0);
    snprintf (_mqtt_msg, 75, "{\"command\" : \"addlogmessage\", \"message\" : \"Hola\" }");


    Serial.print("Publish message: ");
    Serial.println(_mqtt_msg);
    client.publish(DOMOTICZ_IN_TOPIC, _mqtt_msg);
  }
}

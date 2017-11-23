#if DEBUGOUTPUT == DEBUGOUTPUTTELNET

#include <ESP8266WiFi.h>


// declare telnet server (do NOT put in setup())
WiFiServer TelnetServer(23);
WiFiClient Telnet;

void telnetSetup(){
  TelnetServer.begin();
}

void telnetLoop(){
  if (TelnetServer.hasClient()){
  	// client is connected
    if (!Telnet || !Telnet.connected()){
      if(Telnet) Telnet.stop();          // client disconnected
      Telnet = TelnetServer.available(); // ready for new client
    } else {
      TelnetServer.available().stop();  // have client, block new conections
    }
  }
  if (Telnet && Telnet.connected() && Telnet.available()){
    // client input processing
    while(Telnet.available()){
      char inChar = Telnet.read();
      // no hace nada con lo recibido
    }
  }
}

void sendTelnet(char *msg){
  Telnet.print(msg);
}

#endif

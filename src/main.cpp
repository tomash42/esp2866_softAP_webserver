#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "wsiz";
const char *password = "12345678";

//setup IP
IPAddress local_IP(192,168,10,10);
IPAddress gateway(192,168,10,1);
IPAddress subnet(255,255,255,0);

AsyncWebServer server(80);


void setup() {
Serial.begin(9600);


Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
Serial.print("Setting soft-AP ... ");
Serial.println(WiFi.softAP(ssid,password) ? "Ready" : "Failed!");
Serial.print("Soft-AP IP address = ");
Serial.println(WiFi.softAPIP());

//route for root /web page
server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "https://randomnerdtutorials.com/esp8266-nodemcu-access-point-ap-web-server/");
     Serial.println("New conection");
  });
 server.begin();
}



void loop() {
  // put your main code here, to run repeatedly:
}


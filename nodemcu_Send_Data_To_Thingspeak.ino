#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "1 FLOOR";
const char* pass = "12345678";
unsigned long myChannelNumber = 824791;
const char * myWriteAPIKey = "NNOXQNO4JOPNH2NB";
 
int randomvalue;

WiFiClient client;
 
void setup(){
 
      Serial.begin(9600);
      delay(10);
      WiFi.disconnect();
                 
      Serial.println("Connecting to ");
      Serial.println(ssid); 
   
      WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 
      ThingSpeak.begin(client);
    
}
 
void loop(){

    randomvalue = random(100);
    Serial.println("Value to be uploaded is:" + String(randomvalue));
    ThingSpeak.writeField(myChannelNumber, 1,randomvalue, myWriteAPIKey);
    delay(18000);
   
 
}

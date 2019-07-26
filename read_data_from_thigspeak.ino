#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "1 FLOOR";
const char* pass = "12345678";
unsigned long myChannelNumber = 824791;
const char * myReadAPIKey = "MD73DF2RXRMDHPM7";
 
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

    int fetchedvalue = ThingSpeak.readIntField(myChannelNumber,1,myReadAPIKey);
    int fetchedvalue2 = ThingSpeak.readIntField(myChannelNumber,2,myReadAPIKey);
    Serial.println("the fetched value from field 1 is :"+String(fetchedvalue));
    Serial.println("the fetched value from field 2 is :"+String(fetchedvalue2));
    delay(5000);
   
 
}

#include <ESP8266WiFi.h>

const char* ssid = "";//ssid 
const char* password = "";//password
const char* host = "maker.ifttt.com";
int count =1;

void setup() {
    Serial.begin(115200);

    Serial.println("Email from Node Mcu");
    delay(100);

    Serial.print("Connecting to ");
    Serial.println(ssid);
    
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  
    Serial.println("");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());  

}         

void loop() {
 WiFiClient client; 
            const int httpPort = 80;  
            if (!client.connect(host, httpPort)) {  
                  Serial.println("connection failed");  
            return;
            }       
    long state = digitalRead(D2);    
    if(state == HIGH) {
                  if(count==2) { String url = "/trigger/motion%20detected/with/key/f70d3RB1S602trwQoQpR1djUKj1ZIhsu27lnz9P2XRO"; 
                    Serial.println("Motion detected!!");
                    Serial.print("Requesting URL: ");
                    Serial.println(url);
                    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n"+"Connection: close\r\n\r\n");
                      }  
                    else if(count>2)
                    {
                      Serial.println("Motion Detected!!");
                    }
                    count++; 
                    delay(5000);
                    }                        
      else if(state==LOW) {
          Serial.println("didnt deteceted");
        }
}

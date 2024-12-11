#define BLYNK_TEMPLATE_ID "TMPL68r2ehzUY"
#define BLYNK_TEMPLATE_NAME "Control Fan"
#define BLYNK_AUTH_TOKEN "Your Auth Token"

#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DNSServer.h>

char ssid[] = "Redmi K50 Ultra";  
char pass[] = "123454321";  
#define RELAY_PIN D1  
#define PWM_PIN D2     
BLYNK_WRITE(V1) {  
  int state = param.asInt();  
  if (state == 1) {
    analogWrite(PWM_PIN, 85);  
  } else {
    analogWrite(PWM_PIN, 0);   
  }
}

BLYNK_WRITE(V2) {  
  int state = param.asInt();  
  if (state == 1) {
    analogWrite(PWM_PIN, 170);  
  } else {
    analogWrite(PWM_PIN, 0);    
  }
}

BLYNK_WRITE(V3) {  
  int state = param.asInt();  
  if (state == 1) {
    analogWrite(PWM_PIN, 255);  
  } else {
    analogWrite(PWM_PIN, 0);    
  }
}
BLYNK_WRITE(V4) {  
  int state = param.asInt();  
  if (state == 1) {
    analogWrite(PWM_PIN, 0);  
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);  


  digitalWrite(RELAY_PIN, LOW);
  analogWrite(PWM_PIN, 0);
}

void loop() {
  Blynk.run();  
}
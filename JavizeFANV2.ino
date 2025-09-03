#define BLYNK_TEMPLATE_ID "TMPL6vW_xCGlN"
#define BLYNK_TEMPLATE_NAME "JavizeFAN V2"

#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

#define BT1 D1 
#define BT2 D2 
#define BT3 D3
#define BT5 D5  


 char auth[] = "Blink_AUTH";
 char ssid[] = "Wifi_SSID";
 char pass[] = "Wifi_PW";
 
WidgetLCD lcd1(V0);
WidgetLED BT1Blynk(V10);
WidgetLED BT2Blynk(V11);
WidgetLED BT3Blynk(V12);
WidgetLED BT5Blynk(V13);

void setup()
{
  // Debug console
  digitalWrite(BT1, LOW);
  digitalWrite(BT2, LOW);
  digitalWrite(BT3, LOW);
 delay(100);
  Serial.begin(9600);
   Blynk.begin(auth, ssid, pass);
    lcd1.clear(); 
    lcd1.print(3,0,"JavizeFAN"); 
    lcd1.print(5,1,"Controller"); 
  pinMode(BT1,OUTPUT); 
  pinMode(BT2,OUTPUT); 
  pinMode(BT3,OUTPUT);
  pinMode(BT5,OUTPUT);  
}

void loop()
{
  Blynk.run();
}
BLYNK_WRITE(V1){ 
  Serial.println(param.asInt()); 
    if (param.asInt()){ 
        digitalWrite(BT1, LOW);
     lcd1.clear(); 
     lcd1.print(4,0,"On Number"); 
     lcd1.print(8,1,"1");  
     BT1Blynk.on();
     digitalWrite(BT2, HIGH); 
     BT2Blynk.off();
     digitalWrite(BT3, HIGH); 
     BT3Blynk.off();
     digitalWrite(BT5, HIGH); 
     BT5Blynk.off();
     Blynk.virtualWrite(V2,0);
     Blynk.virtualWrite(V3,0);
     Blynk.virtualWrite(V5,0);
    } else {
      digitalWrite(BT1, HIGH); 
      lcd1.clear();
      lcd1.print(7,0,"Off");
      BT1Blynk.off();
    }
}
BLYNK_WRITE(V2){ 
  Serial.println(param.asInt()); 
    if (param.asInt()){ 
      digitalWrite(BT2, LOW);
     lcd1.clear(); 
     lcd1.print(4,0,"On Number"); 
     lcd1.print(8,1,"2");  
     BT2Blynk.on();
     BT1Blynk.on();
     digitalWrite(BT1, HIGH); 
     BT1Blynk.off();
     digitalWrite(BT3, HIGH); 
     BT3Blynk.off();
     digitalWrite(BT5, HIGH); 
     BT5Blynk.off();
     Blynk.virtualWrite(V1,0);
     Blynk.virtualWrite(V3,0);
     Blynk.virtualWrite(V5,0);
    } else {
        digitalWrite(BT2, HIGH); 
        lcd1.clear();
        lcd1.print(7,0,"Off");
         BT2Blynk.off();
    }
}
BLYNK_WRITE(V3){ 
  Serial.println(param.asInt()); 
    if (param.asInt()){ 
      digitalWrite(BT3, LOW);
     lcd1.clear(); 
     lcd1.print(4,0,"On Number"); 
     lcd1.print(8,1,"3");  
      BT3Blynk.on();
     digitalWrite(BT1, HIGH); 
     BT1Blynk.off();
     digitalWrite(BT2, HIGH); 
     BT2Blynk.off();
     digitalWrite(BT5, HIGH); 
     BT5Blynk.off();
    Blynk.virtualWrite(V1,0);
    Blynk.virtualWrite(V2,0);
    Blynk.virtualWrite(V5,0);
    } else {
        lcd1.clear();
        lcd1.print(7,0,"Off");
        digitalWrite(BT3, HIGH); 
         BT3Blynk.off();
    }
}
BLYNK_WRITE(V5){ 
  Serial.println(param.asInt()); 
    if (param.asInt()){ 
      digitalWrite(BT5, LOW);
     lcd1.clear(); 
     lcd1.print(4,0,"On Number"); 
     lcd1.print(8,1,"2");  
     BT5Blynk.on();
     BT1Blynk.on();
     digitalWrite(BT1, HIGH); 
     BT1Blynk.off();
     digitalWrite(BT2, HIGH); 
     BT3Blynk.off();
     digitalWrite(BT3, HIGH); 
    BT3Blynk.off();
     Blynk.virtualWrite(V1,0);
     Blynk.virtualWrite(V2,0);
     Blynk.virtualWrite(V3,0);
    } else {
        digitalWrite(BT5, HIGH); 
        lcd1.clear();
        lcd1.print(7,0,"Off");
         BT5Blynk.off();
    }
}  BLYNK_WRITE(V4){ 
  Serial.println(param.asInt()); 

    lcd1.clear();
    lcd1.print(5,0,"Off All");
    BT1Blynk.on();
    digitalWrite(BT1, HIGH); 
    BT1Blynk.off();
    digitalWrite(BT2, HIGH); 
    BT2Blynk.off();
    digitalWrite(BT3, HIGH); 
    BT3Blynk.off();
    digitalWrite(BT5, HIGH); 
    BT5Blynk.off();
    Blynk.virtualWrite(V1,0);
    Blynk.virtualWrite(V2,0);
    Blynk.virtualWrite(V3,0);
    Blynk.virtualWrite(V5,0);
   }
 

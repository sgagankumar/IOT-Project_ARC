#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
int ir1 = D1;
int ir2=D2;

void setup() {
  // put your setup code here, to run once:

   Wire.begin(D6,D7);   
  
   lcd.init();
   
   lcd.begin(16,2);
   lcd.backlight();
    
    pinMode(ir1, INPUT);
       pinMode(ir2, INPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
int ReadIr1 = digitalRead(ir1);
int ReadIr2 = digitalRead(ir2);

if(ReadIr1==LOW && ReadIr2==LOW)
{ lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("THANK YOU");
  lcd.setCursor(0,1);
   lcd.print("TEQUED LABS");
    delay(5000);
    
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DRIVE SAFE");
  lcd.setCursor(0,1);
   lcd.print("HAVE A GOOD DAY");
    delay(5000);
    
  
}
else if(ReadIr1==LOW && ReadIr2==HIGH)
{lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TRAIN IS COMING");
  lcd.setCursor(0,1);
  lcd.print("PLEASE STOP");
 
  delay(500);
  

  
}
  else if(ReadIr1==HIGH && ReadIr2==LOW)
{lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GATE CLOSING");
  lcd.setCursor(0,1);
  lcd.print("PLEASE WAIT");
    delay(500);
  
      
}

  else if(ReadIr1==HIGH && ReadIr2==HIGH)
{ lcd.clear();
 lcd.setCursor(0,0);
   lcd.print("TRAIN LEAVING");
   lcd.setCursor(0,1);
  lcd.print("PLEASE WAIT");
      delay(500);
}
}

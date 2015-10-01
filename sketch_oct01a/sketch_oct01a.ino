#include <Wire.h>
#include <LiquidCrystal.h> 
#include <DHT.h>
#include <Adafruit_BMP085.h>

#define DHTPIN 0
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 bmp;


int GREEN=9;
int RED=6;

int CURRENT_FRAME=0;
int PREVIOUS_FRAME=0;
int INTERVAL=1000;

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

void setup() {
   Serial.begin(9600); 

   dht.begin();
   
   if (!bmp.begin()) {
        Serial.println("Could not find a BMP sensor, check wiring!");
   }
            else {
                  pinMode (GREEN,OUTPUT);
   }
   
   lcd.begin(20, 4);
   lcd.print("I like my job"); 
   delay(500);                
   lcd.print(".");
   delay(500);                
   lcd.print(".");
   delay(500);                
   lcd.print(".");
   delay(1000);              
   lcd.clear();  
   
}

void loop() {
   
  analogWrite  (GREEN, 135+random(120));
  analogWrite  (RED, 135+random(120));

  float h = dht.readHumidity();
  float tC = dht.readTemperature();
  float Pa = bmp.readPressure();
  float Hm = bmp.readAltitude();

  int MODE = 1;

  CURRENT_FRAME++;
  
  if (CURRENT_FRAME-PREVIOUS_FRAME == INTERVAL ){
     if (MODE == 1){
        MODE=2;
     }
     else{
      MODE=1;
     }
      PREVIOUS_FRAME=CURRENT_FRAME;
      lcd.clear();   
  }
  
   if (MODE ==1){

  lcd.setCursor(0, 0); 
  lcd.print("Temperature = ");
  lcd.setCursor(12, 0); 
  lcd.print(tC,1); 
  lcd.println(" °C");

  lcd.setCursor(0, 2); 
  lcd.print("Pressure = ");
  lcd.setCursor(8, 2); 
  lcd.print(Pa,1);
  lcd.println(" Pa");
   }
    else {
      
  lcd.setCursor(0, 1); 
  lcd.print("Humidity = ");
  lcd.setCursor(9, 1); 
  lcd.print(h, 1); 
  lcd.println(" %");

  
  
  lcd.setCursor(0, 3); 
  lcd.print("Attitude = ");
  lcd.setCursor(8, 3); 
  lcd.print(Hm, 1); 
  lcd.println(" m");
    }


  
  
  
  

  
}

#include <DHT.h>
#include <LiquidCrystal.h> 
#include <Wire.h>
#include <Adafruit_BMP085.h>

#define DHTPIN 0
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);

Adafruit_BMP085 bmp;

int GREEN=9;
int RED=6;
const int buttonPin = 8;
int buttonState = 0;

LiquidCrystal lcd(12, 11, 10, 5,4, 3, 2);

void setup() {
  
   Serial.begin(9600); 
   Serial.println("DHT22 test!");
   dht.begin();
 
   pinMode(buttonPin, INPUT);
   if (!bmp.begin()) {
   lcd.println("Could not find a BMP sensor, check wiring!");
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
  
  analogWrite  (GREEN, random(120)+135);
  analogWrite  (RED, random(120)+135);
  
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();


  
  lcd.setCursor(0, 0); 
  lcd.print("Humidity = ");
  lcd.setCursor(9, 0); 
  lcd.print(h, 1); 
  lcd.println(" %");

  lcd.setCursor(0, 1); 
  lcd.print("Temperature = ");
  lcd.setCursor(12, 1); 
  lcd.print(t,1); 
  lcd.println(" °C");

  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");
    
  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");
    

  Serial.print("Altitude = ");
  Serial.print(bmp.readAltitude());
  Serial.println(" meters");

  Serial.print("Pressure at sealevel (calculated) = ");
  Serial.print(bmp.readSealevelPressure());
  Serial.println(" Pa");


  Serial.print("Real altitude = ");
  Serial.print(bmp.readAltitude(101500));
  Serial.println(" meters");
    
  Serial.println();
  delay(500);


  

  buttonState = digitalRead(buttonPin);
 
  if (buttonState == HIGH) {   
    
  lcd.setCursor(0, 1); 
  lcd.print("Temperature = ");
  lcd.setCursor(7, 1); 
  lcd.print(t,1); 
  lcd.println(" °C");
   
  }
  else {
    
  lcd.setCursor(0, 1); 
  lcd.print("Temperature  ");
  lcd.setCursor(7, 1); 
  lcd.print(t,1); 
  lcd.println(" °C");  
   
  }
 


}
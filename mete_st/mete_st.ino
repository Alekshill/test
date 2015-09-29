#include <DHT.h>
#include <LiquidCrystal.h> 
#include <Wire.h>
#include <Adafruit_BMP085.h>

#define DHTPIN 0
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);

Adafruit_BMP085 bmp;

int GREEN=9;
const int buttonPin = 8;
int buttonState = 0;

LiquidCrystal lcd(12, 11, 10, 5,4, 3, 2);



void setup() {
  
   Serial.begin(9600); 
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
    
  float h = dht.readHumidity();
  float tC = dht.readTemperature();
  
  lcd.setCursor(0, 0); 
  lcd.print("Humidity = ");
  lcd.setCursor(9, 0); 
  lcd.print(h, 1); 
  lcd.println(" %");

  lcd.setCursor(0, 1); 
  lcd.print("Temperature = ");
  lcd.setCursor(12, 1); 
  lcd.print(tC,1); 
  lcd.println(" °C");
 
 buttonState = digitalRead(buttonPin);
 
  if (buttonState == HIGH) { 
      
  // tF=((9/5)*tC)+32
  
  float tF =((9.0/5.0)*tC)+32.0;
  lcd.setCursor(0, 1); 
  lcd.print("Temperature = ");
  lcd.setCursor(12, 1); 
  lcd.print(tF,1); 
  lcd.println(" °F");
   
  }
  else {
    
  lcd.setCursor(0, 1); 
  lcd.print("Temperature = ");
  lcd.setCursor(12, 1); 
  lcd.print(tC,1); 
  lcd.println(" °C");  
   
  }
 }

/*
Demonstration sketch for PCF8574T I2C LCD Backpack
http://tronixlabs.com/display/lcd/serial-i2c-backpack-for-hd44780-compatible-lcd-modules/
Uses library from https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
GNU General Public License, version 3 (GPL-3.0)
*/

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified backpack
int echoPin = 10; 
int trigPin = 8; 

void setup()
{
  // activate LCD module
  lcd.begin (16,2); // for 16 x 2 LCD module
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}

void loop()
{
  int duration, cm; 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  cm = duration / 58;
 // lcd.home (); // set cursor to 0,0
  Serial.print(cm); 
 // lcd.print(" CM");
 // lcd.print("   ");      // go to start of 2nd line
  //lcd.setBacklight(HIGH);     // Backlight on
  delay(1000);
  }

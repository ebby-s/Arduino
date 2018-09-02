#include <LiquidCrystal.h>

#include <dht.h>
dht DHT;
#define DHT11_PIN 4
#define contrast_pin 5

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

void setup() { 
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.write("Temp:");
  lcd.setCursor(7,0);
  lcd.write("Humidity:");
  analogWrite(contrast_pin,128);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  Serial.println(DHT.temperature);
  Serial.println(DHT.humidity);
  lcd.setCursor(0,1);
  lcd.print(DHT.temperature);
  lcd.setCursor(7,1);
  lcd.print(DHT.humidity);
  delay(2000);
}


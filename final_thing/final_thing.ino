#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

#include <dht.h>
#define DHT11_PIN 4
dht DHT;

#define contrast_pin 5

int RX1 = 3;
int TX1 = 2;
SoftwareSerial ser(RX1,TX1);
String apiKey = "Y37C6WL1SAXU6A2F";

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

void setup() { 
  pinMode(RX1,INPUT);
  pinMode(TX1,OUTPUT);
  Serial.begin(9600);
  ser.begin(9600);
  Serial.println("Test Start");
  ser.println("AT+CWJAP=\"benjamin2\",\"Anitha2873\"");
  Serial.setTimeout(5000);
  analogWrite(contrast_pin,128);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.write("Temp:");
  lcd.setCursor(7,0);
  lcd.write("Humidity:");
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  Serial.println(DHT.temperature);
  Serial.println(DHT.humidity);
  lcd.setCursor(0,1);
  lcd.print(DHT.temperature);
  lcd.setCursor(7,1);
  lcd.print(DHT.humidity);

  // convert to string
  char buf[16];
  String strval = dtostrf(DHT.temperature, 4, 1, buf);
  String strval2 = dtostrf(DHT.humidity, 4, 1, buf);

  Serial.println(strval);

  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149";
  cmd += "\",80";
  ser.println(cmd);

  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }

  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field1=";
  getStr += String(strval);
  getStr += "&field3=";
  getStr += String(strval2);
  getStr += "\r\n\r\n";

  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ser.println(cmd);
  
  if(ser.find(">")){
    ser.print(getStr);
  }
  else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }

  // thingspeak needs 15 sec delay between updates
  delay(16000);  
}


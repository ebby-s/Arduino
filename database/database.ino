
#include <SoftwareSerial.h>
#include <stdlib.h>

const int RX1 = 11;
const int TX1 = 10;

int led = 13;

int sensor = 8;

int sensetrig = 7;

String apiKey = "apikey";

SoftwareSerial ser(RX1,TX1);

void setup() 
{                
  pinMode(led, OUTPUT);    

  Serial.begin(9600);

  ser.begin(9600);

  ser.println("AT+RST");
  ser.println("AT+CWJAP=\"SSID\",\"password\"");
  pinMode(sensetrig, OUTPUT);
  pinMode(sensor, INPUT);
  
}


void loop() {

  digitalWrite(led, HIGH);   
  delay(200);               
  digitalWrite(led, LOW);

  // for analogue inputs
  //int val = 0;
  //val = analogRead(sensor);


  // manipulate "val"
  //float finalval = val;
  long duration, distance;
  digitalWrite(sensetrig, LOW);
  delay(2);
  digitalWrite(sensetrig, HIGH);
  delay(10);
  digitalWrite(sensetrig, LOW);
  duration = pulseIn(sensor, HIGH);
  distance = (duration/2) / 29.1;

  // convert to string
  char buf[16];
  String strval = dtostrf(distance, 4, 1, buf);

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
  getStr +="&field2=";
  getStr += String(strval);
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

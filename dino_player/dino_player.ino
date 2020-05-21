#include <Servo.h>

Servo motor;
int light, pos;

void setup() {
  motor.attach(3);
  Serial.begin(9600);
}

void loop() {
  light = analogRead(A0);
  Serial.println(light);
  if(light>293){
    motor.write(173);
  }else{
    motor.write(160);
  }
  delay(5);
}

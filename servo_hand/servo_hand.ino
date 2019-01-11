#include <Servo.h>

Servo base;
Servo mid;
Servo tip;

int base_pos = 90;
int mid_pos = 90;
int tip_pos = 90;

void setup() {
  base.attach(9);
  mid.attach(9);
  tip.attach(9);
}

void loop() {
  
  base.write(base_pos);
  mid.write(mid_pos);
  tip.write(tip_pos);
  delay(25);
}

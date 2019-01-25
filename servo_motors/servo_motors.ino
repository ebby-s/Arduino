#include <Servo.h>

Servo base;
Servo mid;

int base_pos = 0;
int mid_pos = 0;

void setup() {
  base.attach(10);
  mid.attach(9);
}

void loop() {
  for (base_pos=0;base_pos<=180;base_pos++){
    base.write(base_pos);
    mid.write(180-base_pos);
    delay(25);
  }
  for (base_pos=180;base_pos>=0;base_pos--){
    base.write(base_pos);
    mid.write(180-base_pos);
    delay(25);
  }
}

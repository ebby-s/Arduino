int leds[] = {3,5,6,9,10,11};
int pwm_lvls[] = {3,4,5,6,7,8};
float change = 0.0625;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0;i<=5;i++){
    pwm_lvls[i]-=change;
    if (pwm_lvls[i]<=0){
      pwm_lvls[i] = 7.99 + pwm_lvls[i];
    }
  }
  for (int i=0;i<=5;i++){
    analogWrite(leds[i],pow(2,pwm_lvls[i]));
  }
  delay(60);

}

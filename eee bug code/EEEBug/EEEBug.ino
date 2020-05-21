#include<Servo.h>

Servo eye1;
Servo eye2;
int pos1 = 0;
int pos2 = 0;
long uptime = 0;
const long INTERVAL = 4000;

long fact(int x){
  if(x<=1){
    return 1;
  }else{
    return x*fact(x-1);
  }
}

int EEEBugSin(int x){
  double acc = 0;
  double y = x*3.1415/128;
  for(int n=0;n<5;n++){
    acc += pow(-1,n)*pow(y,2*n+1)/fact(2*n+1);
  }
  acc += 1;
  acc *= 127;
  return (int)acc;
}

void setup() {
  // put your setup code here, to run once:
  eye1.attach(6);
  eye2.attach(5);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=-128;i<128;i++){
    
    while(micros() < uptime) {}    // delay
    uptime += INTERVAL;
    
    analogWrite(5,EEEBugSin(i-128));  // write sin wave to pin 5
    
    pos1 = i;
    pos2 = i+128;                    // values between 0 and 128 phase shift eye2 by
    if(pos2>=128) pos2 -= 256;
    
    eye1.write(75+(int)EEEBugSin(pos1)*40/255);   // set new positions of eyes
    eye2.write(75+(int)EEEBugSin(pos2)*40/255);
  }

}

#include<Servo.h>

Servo eye_r;
Servo eye_l;
int pos_r = 0;
int pos_l = 0;
int light_r;
int light_l;
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
  pinMode(A0, INPUT);   // right eye
  pinMode(A1, INPUT);   // left eye
  //pinMode(10, OUTPUT);  // right motor
  //pinMode(9, OUTPUT);   // left motor
  eye_r.attach(6);      // right servo
  eye_l.attach(5);      // left servo

}

void loop() {
  // put your main code here, to run repeatedly:
  int max_r = 0;
  int max_l = 0;

  for(int i=-128;i<128;i+=2){
    
    while(micros() < uptime) {}    // delay
    uptime += INTERVAL;
    
    pos_r = i;
    pos_l = i;           // values between 0 and 128 phase shift eye2
    if(pos_l>=128) pos_l -= 256;
    eye_r.write(30+(int)EEEBugSin(pos_r)*120/255);   // set new positions of eyes
    eye_l.write(30+(int)EEEBugSin(pos_l)*120/255);

    light_r = analogRead(A0);             // read value from eyes
    light_l = analogRead(A1)*0.66;
    if(light_r>max_r) max_r = light_r;
    if(light_l>max_l) max_l = light_l;
    
    
  }
  if(light_l<80 && light_r<80){
    analogWrite(9,0);
    analogWrite(10,0);
  }else{
    if(max_r > max_l){          // move motors
      analogWrite(9,255);
      analogWrite(10,0);
    }else{
      analogWrite(9,0);
      analogWrite(10,255);
    }
  }

}

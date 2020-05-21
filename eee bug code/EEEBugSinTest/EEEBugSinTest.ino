long fact(int x){
  if(x<=1){
    return 1;
  }else{
    return x*fact(x-1);
  }
}

int EEEBugSin(int x){
  double acc = 0;
  double y = x*3.1415/127;
  for(int n=0;n<5;n++){
    acc += pow(-1,n)*pow(y,2*n+1)/fact(2*n+1);
  }
  acc += 1;
  acc *= 127;
  return (int)acc;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=-128;i<128;i++){
    Serial.println(EEEBugSin(i));
  }

}

int value;

void setup(){
  Serial.begin(9600);
}

void loop(){
  value = analogRead(A0);   //Read analog value 
  value = constrain(value,400,1023);  //Keep the ranges!
  value = map(value,400,1023,100,0);  //Map value : 400 will be 100 and 1023 will be 0
  Serial.print("Soil humidity: ");
  Serial.print(value);
  Serial.println('%');
  delay(2000); //Read every 2 sec.
}

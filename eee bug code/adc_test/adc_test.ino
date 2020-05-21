void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int VA0 = analogRead(A0);
  int VA1 = analogRead(A1);

  Serial.print(VA0);
  Serial.write(' ');
  Serial.println(VA1);

  delay(100);

}

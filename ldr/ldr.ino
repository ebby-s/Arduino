void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int A = analogRead(A0);
  Serial.println(A);
}

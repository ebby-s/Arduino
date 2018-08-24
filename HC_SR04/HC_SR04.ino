int sensor = 2;
int trigger = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(sensor, INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(trigger, LOW);
  delay(2);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(sensor, HIGH);
  distance = duration/58.2;

  char buf[16];
  String strval = dtostrf(distance, 4, 1, buf);

  Serial.print("Distance:");
  Serial.println(strval);

}

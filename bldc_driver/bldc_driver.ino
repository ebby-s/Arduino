#include <Servo.h>
Servo esc_signal;

void setup()
{
  esc_signal.attach(12);  //Specify here the pin number on which the signal pin of ESC is connected.
  esc_signal.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(3000);            //ESC initialization delay.
}

float a;
int s;

void loop()
{
  a = analogRead(0);
  s = (a/1024)*130;
  esc_signal.write(s);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
  delay(15);
}
int trigpin=7;
int echopin=8;
int t; 
int d;
int as
void setup() {
  // put your setup code here, to run once:
pinMode(trigpin,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigpin,HIGH);
//delayMicroseconds(10);
digitalWrite(trigpin,LOW);
t=pulseIn(echopin,HIGH);

d=(t/2)*0.034;

Serial.println(d);

}

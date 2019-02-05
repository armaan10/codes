int trig=4;
int echo=2;
unsigned long t1=0,t2=0,t;
int d;

void setup() {
  // put your setup code here, to run once:

pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:


digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);//clear
//delayMicroseconds(5);
while(digitalRead(echo)==LOW);
//wait till echo is high
t1=micros();
while(digitalRead(echo)==HIGH);
//wait till echo is low 
t2=micros();
t=t2-t1;
d=t/2*0.034;

Serial.println(d);
//Serial.print("time1:");
//Serial.println(t1);
//Serial.print("time2:");
//Serial.println(t2);
//Serial.println("next");


}

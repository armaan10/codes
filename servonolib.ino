
int servopin=8;

void setup() {
  // put your setup code here, to run once:
pinMode(servopin,OUTPUT);
}
void servo(int angle)
{
  double x=(1/180*angle)+1;
  digitalWrite(servopin,HIGH);
  delay(x);
  digitalWrite(servopin,LOW);
  delay(20-x);
  
  
  }
void loop() {
  // put your main code here, to run repeatedly:

/*for(int i=400;i<=900;i++)
{
  
digitalWrite(servopin,HIGH);
delayMicroseconds(i);
digitalWrite(servopin,LOW);
delayMicroseconds(200000-i);

  
  }delay(2000);/*
 /* for(int i=400;i<=2400;i--)
{
  
digitalWrite(servopin,HIGH);
delayMicroseconds(i);
digitalWrite(servopin,LOW);
delayMicroseconds(200000-i);

  
  }*/
  digitalWrite(servopin,HIGH);
delayMicroseconds(900);
digitalWrite(servopin,LOW);
delayMicroseconds(200000-900);
   
}

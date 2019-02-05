int trig1=4,trig2=5;
int echo1=2,echo2=3;
unsigned long t1,t2;
int wheelleft_forward=10,wheelright_forward=8,wheelright_backward=9,wheelleft_backward=11;
int d1,d2;
void setup() {
  // put your setup code here, to run once:
pinMode(trig1,OUTPUT);
pinMode(trig2,OUTPUT);
pinMode(wheelleft_forward,OUTPUT);
pinMode(wheelright_forward,OUTPUT);
pinMode(wheelleft_backward,OUTPUT);
pinMode(wheelright_backward,OUTPUT);


Serial.begin(9600);
}
unsigned long pulse(int echo)
{unsigned long t1,t2;
  while(digitalRead(echo)==LOW);//wait till it goes high
  t1=micros();
  while(digitalRead(echo)==HIGH);//wait till it goes back low
t2=micros();
return t2-t1;
  
}
void bruteStop()
{
//reverse
while(d1<8||d2<8)
{/*digitalWrite(wheelleft_backward,1); 
  digitalWrite(wheelright_backward,1);
digitalWrite(wheelleft_forward,0); 
  digitalWrite(wheelright_forward,0);
 //delay(2000);*/
 ultra(trig1);
  t1=pulse(echo1);
  ultra(trig2);
  
  t2=pulse(echo2);
  d1=getdist(t1);  
  d2=getdist(t2);
Serial.println("back");
}
 if(d1<d2)
{ /*digitalWrite(wheelleft_forward,0); 
  digitalWrite(wheelright_forward,1);
digitalWrite(wheelleft_backward,1); 
  digitalWrite(wheelright_backward,0);
  */Serial.println("right");
  delay(1000);}
  else
  {/*digitalWrite(wheelleft_forward,1); 
  digitalWrite(wheelright_forward,0);
  digitalWrite(wheelleft_backward,0); 
  digitalWrite(wheelright_backward,1);
  */
  Serial.println("left");
  delay(1000);
  }
}

void ultra(int trig)
{
  digitalWrite(trig,LOW);
delayMicroseconds(10);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
  }

int getdist(unsigned long t)
{
int d=0.034*t/2;
return d;
  
}


void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig1,LOW);
delayMicroseconds(10);
digitalWrite(trig1,HIGH);
delayMicroseconds(10);
digitalWrite(trig1,LOW);
t1=pulse(echo1);
digitalWrite(trig2,LOW);
delayMicroseconds(10);
digitalWrite(trig2,HIGH);
delayMicroseconds(10);
digitalWrite(trig2,LOW);
t2=pulse(echo2);
d1=t1/2*0.034;//d1 left d2 right
d2=t2/2*0.034;
if(d1<8||d2<8)
bruteStop();

if(d1<d2)
{
  if(d1<20)
  {while(d1<20){
    /*digitalWrite(wheelleft_forward,0); 
    digitalWrite(wheelright_forward,1);
    digitalWrite(wheelleft_backward,1); 
    digitalWrite(wheelright_backward,0);
    //delay(1000);
    */
    Serial.println("left");
  
   ultra(trig1);
   t1=pulse(echo1);
   d1=getdist(t1);
  
  } 
  //Serial.println(d1);
  }}

else if (d2<20)
{while(d2<20)
{/*digitalWrite(wheelleft_forward,1); 
  digitalWrite(wheelright_forward,0);
  digitalWrite(wheelleft_backward,0); 
  digitalWrite(wheelright_backward,1);
   */
   //delay(1000);
   Serial.println("left");
 
  ultra(trig2);
  t2=pulse(echo2);
  d2=getdist(t2);
}
}



if(d1>20&&d2>20)
{while(d1>20&&d2>20)
  {/*digitalWrite(wheelleft_forward,1); 
  digitalWrite(wheelright_forward,HIGH);
  digitalWrite(wheelleft_backward,0); 
  digitalWrite(wheelright_backward,0);
  *///delay(1000);
 
  ultra(trig1);
  t1=pulse(echo1);
  ultra(trig2);
 Serial.println("forawrd");
  t2=pulse(echo2);
  d1=getdist(t1);  
  d2=getdist(t2);
  }}


/*Serial.print("dist1:");
Serial.println(d1);
Serial.print("dist2:");
Serial.print(d2);
















*/
}

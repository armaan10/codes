int output1=2;
int output2=3;
int inpin=8;
boolean current=LOW;
boolean lastbutton=LOW;
int count=-1;


void setup() {
  // put your setup code here, to run once:
pinMode(inpin,INPUT);
pinMode(output1,OUTPUT);
pinMode(output2,OUTPUT);
}
boolean debounce(boolean last)
{boolean curr=digitalRead(inpin);
if(curr=!last)
{
  delay(50);
  
}curr=digitalRead(inpin);
return curr;
  
}

void loop() {
  // put your main code here, to run repeatedly:

current=debounce(lastbutton);
if(current==HIGH&&lastbutton==LOW)
{count=(count+1)%4;
switch(count)
{case 0:
digitalWrite(output1,LOW);
digitalWrite(output2,LOW);    
break;
case 1:
digitalWrite(output1,HIGH);
digitalWrite(output2,LOW);    
break;
case 2:
digitalWrite(output1,LOW);
digitalWrite(output2,HIGH);    
break;
case 3:
digitalWrite(output1,HIGH);
digitalWrite(output2,HIGH);    

break;





}}
lastbutton=current;

}


boolean lastbutton=LOW;
boolean currbutton=LOW;
int ledpin2=4;
int ledpin1=2;
int ledpin0=3;
int inpin=8;
int count=-1;
void setup() {
  // put your setup code here, to run once:
pinMode(inpin,INPUT);
pinMode(ledpin0,OUTPUT);
pinMode(ledpin1,OUTPUT);
pinMode(ledpin2,OUTPUT);

}
boolean debounce(boolean last)
{boolean curr=digitalRead(inpin);
  if(curr!=last)
  {
    delay(50);
  }
  
  curr=digitalRead(inpin);
  return curr; 
  }
void loop() {
  // put your main code here, to run repeatedly:
//currbutton=debounce(lastbutton);
for(count=0;count<8;count++)
{
  count=(count+1)%8;
  switch(count)
  {
    case 0:
    digitalWrite(ledpin0,LOW);
 digitalWrite(ledpin1,LOW);
 digitalWrite(ledpin2,LOW);   
case 1:
    digitalWrite(ledpin0,HIGH);
 digitalWrite(ledpin1,LOW);
 digitalWrite(ledpin2,LOW);   
case 2:
    digitalWrite(ledpin0,LOW);
 digitalWrite(ledpin1,HIGH);
 digitalWrite(ledpin2,LOW);   
case 3:
    digitalWrite(ledpin0,HIGH);
 digitalWrite(ledpin1,HIGH);
 digitalWrite(ledpin2,LOW);   
case 4:
    digitalWrite(ledpin0,LOW);
 digitalWrite(ledpin1,LOW);
 digitalWrite(ledpin2,HIGH);   
case 5:
    digitalWrite(ledpin0,HIGH);
 digitalWrite(ledpin1,LOW);
 digitalWrite(ledpin2,HIGH);   
case 6:
    digitalWrite(ledpin0,LOW);
 digitalWrite(ledpin1,HIGH);
 digitalWrite(ledpin2,HIGH);   
   case 7:
    digitalWrite(ledpin0,HIGH);
 digitalWrite(ledpin1,HIGH);
 digitalWrite(ledpin2,HIGH);   
 
    }delay(5000);
}

//lastbutton=currbutton;
}

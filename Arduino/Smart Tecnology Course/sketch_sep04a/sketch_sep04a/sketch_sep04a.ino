int a=6;
int echo=5;
int trig=4;
int d=0;
int t=0;
int L=8;
void setup() {
  // put your setup code here, to run once:
pinMode (a,OUTPUT);
pinMode(echo,INPUT);
pinMode (trig,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig,LOW);
delay(100);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

t=pulseIn(echo,HIGH);
d=0.0343*(t/2);
Serial.println(d);
delay(5);


if (d<10 && d>5){
tone(a,500, 50);
digitalWrite(L,HIGH);

}else{digitalWrite(a,LOW);
digitalWrite(L,LOW);}

if(d<5){
tone(a,1200,20);
digitalWrite(L,HIGH);

}else{digitalWrite(a,LOW);
digitalWrite(L,LOW);}


}

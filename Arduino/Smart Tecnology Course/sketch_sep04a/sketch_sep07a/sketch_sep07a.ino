int a=7;
char v=0;
int smoke=6;
void setup() {
  // put your setup code here, to run once:
pinMode(a,OUTPUT);
Serial.begin(9600);
pinMode(smoke,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
v=digitalRead(smoke);
Serial.println(v);
delay(150);
if (v==HIGH){
  
  digitalWrite (a,HIGH);
}else{
  digitalWrite (a,LOW);
  }
}

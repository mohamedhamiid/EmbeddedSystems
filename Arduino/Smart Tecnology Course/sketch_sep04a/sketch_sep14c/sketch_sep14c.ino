int L1=8;
void setup() {
  // put your setup code here, to run once:
pinMode(L1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(L1,HIGH);
delay(200);
digitalWrite(L1,LOW);
delay(200);
}

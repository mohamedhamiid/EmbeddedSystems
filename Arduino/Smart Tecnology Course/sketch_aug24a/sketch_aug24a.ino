int L1=5;
int L2=2;
int L3=11;
int x=0;
int c=0;
void setup() {
pinMode ( L1 , OUTPUT);
pinMode ( L2 , OUTPUT);
pinMode ( L3 , OUTPUT);
pinMode (x , INPUT);

}

void loop() {
//x = digitalRead(2);
//delay (150);:
//if (x==HIGH){:
 for (c=0;c<255;c++){
    analogWrite (L1,c);
     delay(2);
     analogWrite (L1,c);
     delay(2);
     analogWrite (L2,c);
     delay(2);
     analogWrite(L2,c);
     delay(2);
     analogWrite (L3,c);
     delay(2);
     analogWrite(L3,c);
     delay (2);
    //}:
  for (c=255;c>0;c--){
  analogWrite (L1,c);
     delay(2);
     analogWrite (L1,c);
     delay(2);
     analogWrite (L2,c);
     delay(2);
     analogWrite(L2,c);
     delay(2);
     analogWrite (L3,c);
     delay(2);
     analogWrite(L3,c);
     delay (2);
  }
}
}

int L1=3;
int L2=5;
int L3=6;
int i=0;
int x=0;
int y=0;
int z=0;
int a=0;
int b=0;
int c=0;
void setup() {
  // put your setup code here, to run once:
pinMode(L1,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
x = analogRead (A0);
y = analogRead (A1);
z=analogRead(A2);
Serial.println(x);

a = map (x,0,1023,0,255);
analogWrite(L1,a);

b=map(y,0,1023,0,255);
analogWrite(L2,b);

c=map(z,0,1023,0,255);
analogWrite(L3,c);




}

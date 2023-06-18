int DO=3; 
int x=0;
void setup() {
  // put your setup code here, to run once:
pinMode(DO,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
x=digitalRead(DO);
Serial.println(x);
}

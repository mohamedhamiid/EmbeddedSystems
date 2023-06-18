int x=0;
void setup() {
  // put your setup code here, to run once:
pinMode(9,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
x=digitalRead(9);
Serial.println(x);
}

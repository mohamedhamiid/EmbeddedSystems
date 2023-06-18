#include<Servo.h>
Servo mo;
int pos=0;

void setup() {
  // put your setup code here, to run once:
mo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
for (pos=0;pos<=180;pos++){
  mo.write(pos);
  delay(15);
  }

for (pos=180;pos>=0;pos--){
  mo.write(pos);
  delay(15);
  }  
}

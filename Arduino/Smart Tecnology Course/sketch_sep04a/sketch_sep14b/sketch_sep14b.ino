int M=0;
int L1=8;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(L1,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
M=analogRead(A0);
Serial.println(M);
if(M>=1000){
  digitalWrite(L1,HIGH);
  }else{digitalWrite(L1,LOW);}
lcd.init(); // or some librarys are lcd.init();
lcd.backlight();
lcd.setCursor(5,0);
lcd.print("READING");
lcd.setCursor(5,1);
lcd.print(M);  
  
}

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
lcd.init(); // or some librarys are lcd.init();
lcd.backlight();
lcd.setCursor(5,0);
lcd.print("Hamid");
lcd.setCursor(5,1);
lcd.print("Anoos");

}
void loop() {
/*for(int i=0;i<15;i++){
lcd.scrollDisplayRight();
delay(50);
}
for(int i=0;i<31;i++){
lcd.scrollDisplayLeft();
delay(50);
}*/
}

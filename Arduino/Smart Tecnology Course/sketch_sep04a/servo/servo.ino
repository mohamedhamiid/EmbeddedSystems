#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Servo.h>
Servo myservo; 
int pos = 0; 
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
int i=(0,0);
int n=0;
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; 
byte colPins[COLS] = {6, 7, 8,9}; 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() {
myservo.attach(9); 
lcd.init(); // or some librarys are lcd.init();
lcd.backlight();}

void loop() {
  
char key = keypad.getKey();
lcd.setCursor(i,0);

if (key){
Serial.print(key);
lcd.print("#");
i++;
if(i==16 || i>16){
  
  lcd.setCursor(n,1);
  lcd.print(key);
  n++;
  }
if (key=='#'){
  lcd.clear();
  }  
}
if(key=='1'){
  for (pos = 0; pos <= 90; pos++) 
{
myservo.write(pos); 
delay(15); 
}
for (pos = 90; pos >= 0; pos--) 
{ 
myservo.write(pos); 
delay(15);
}
}
}

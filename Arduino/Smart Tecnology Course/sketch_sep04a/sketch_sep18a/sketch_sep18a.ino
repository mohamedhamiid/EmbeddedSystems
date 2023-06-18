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
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup(){
Serial.begin(9600);
lcd.init(); // or some librarys are lcd.init();
lcd.backlight();
/*lcd.setCursor(5,0);
lcd.print("Hamid");*/

}
void loop(){
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
}

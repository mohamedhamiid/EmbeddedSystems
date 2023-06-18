 
 #include <Wire.h>             
 #include <Servo.h> 

  /* #include <LiquidCrystal_I2C.h>    
    LiquidCrystal_I2C lcd(0x27,16,2); */
    
 Servo myservo1;  
 int IR1 = 4;    // IR Sensor 1 (enter) 
 int IR2 = 7;     // IR Sensor 2  (exit)
 int Slot = 4;      //Enter Total number of parking Slots  
 int flag1 = 0;  
 int flag2 = 0; 
 
 void setup()  
 {  
  
 pinMode(IR1, INPUT);  
 pinMode(IR2, INPUT);  
 myservo1.attach(9);  
 //myservo1.write(90);  
 Serial.begin(9600); 
 }  
 void loop(){   
 if(digitalRead (IR1) == HIGH && flag1==0)
 {  
 if(Slot>0)
    {
      flag1=1;  
        if(flag2==0) {myservo1.write(0); Slot = Slot-1;}  
    }
   
   Serial.println(IR1);
 }  
 if(digitalRead (IR2) == HIGH && flag2==0)
  {
    flag2=1;  
    if(flag1==0)
    {
    myservo1.write(0); Slot = Slot+1;}  
  }  
 if(flag1==1 && flag2==1)
   {  
   delay (1000); 
   myservo1.write(100);  
   flag1=0, flag2=0;  
   }  
 } 

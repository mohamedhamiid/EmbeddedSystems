#include <NewPing.h>
#include <Servo.h>
#include <AFMotor.h>

//hc-sr04 sensor
#define TRIGGER_PIN A2 // int trigger A2
#define ECHO_PIN A3
#define max_distance 50

//ir sensor
#define IR_Black 1
#define IR_White 0
#define LineT_Black 1
#define LineT_White 0


#define irLeft A0
#define irRight A1
#define irCenter A5
//motor
#define MAX_SPEED 200
#define MAX_SPEED_OFFSET 20

Servo servo;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, max_distance); //ultras

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);


int distance = 0;
int leftDistance;
int rightDistance;
boolean object;

void setup() {
  Serial.begin(9600);
  pinMode(irLeft, INPUT);
  pinMode(irCenter, INPUT);
  pinMode(irRight, INPUT);
  servo.attach(10);
  servo.write(90);

  motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor4.setSpeed(180);
}

void loop() {
  if (digitalRead(irCenter)==LineT_Black ) {
  motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor4.setSpeed(180);
  Serial.println("FWR");
//  moveForward();
   objectAvoid();
    //forword
  }
//  else if (digitalRead(irRight) == IR_White && digitalRead(irCenter)==LineT_White && digitalRead(irLeft) == IR_White) {
//motor1.setSpeed(180);
//  motor2.setSpeed(180);
//  motor3.setSpeed(180);
//  motor4.setSpeed(180);
//  Serial.println("FWRWWW");
////   moveForward();
//    objectAvoid(); 
//    //forword
//  }
//  else if (digitalRead(irRight) == IR_Black && digitalRead(irCenter)==LineT_Black && digitalRead(irLeft) == IR_Black) {
//motor1.setSpeed(180);
//  motor2.setSpeed(180);
//  motor3.setSpeed(180);
//  motor4.setSpeed(180);
//Serial.println("FWRBBB");
//    //moveForward();
//    objectAvoid();
//    //forword
//  }
  else if (digitalRead(irRight) == IR_Black) {
//moveForward();
    //rightturn
     
   moveRight();
   motor1.setSpeed(100);
   motor2.setSpeed(100);
   motor3.setSpeed(100);
   motor4.setSpeed(100);
   Serial.println("TR");
//   delay(100);
  }
  else if (digitalRead(irLeft) == IR_Black ) {
//moveForward();
    
    //leftturn
   moveLeft();
  motor1.setSpeed(100);
   motor2.setSpeed(100);
   motor3.setSpeed(100);
   motor4.setSpeed(100);
//   objectAvoid();
   Serial.println("TL");
//   delay(100);
  }
//  else if (digitalRead(irLeft) == 1 && digitalRead(irRight) == 1 ) {
//    //Stop
//    Stop();
//  }
else {
  motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor4.setSpeed(180);
  Serial.println("FWR");
//  moveForward();
   objectAvoid();
  }
}

void objectAvoid() {
  distance = getDistance();
  if (distance <= 20) {
    //stop
    Stop();
    Serial.println("Stop");

    lookLeft();
    lookRight();
    delay(100);
    ///////////////////////////////////
    if (rightDistance <= leftDistance) { // Left empty
      //left
      object = true;
      turn();
      Serial.println("moveLeft");
    } else {
      //right
      object = false;
      turn();
      Serial.println("moveRight");
    }
    ////////////////////////////////////
    delay(50);
  }
  else {
    //forword
    Serial.println("moveforward");
    moveForward();
  }
}

int getDistance() {
  delay(50);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 100;
  }
  return cm;
}

int lookLeft () {
  //lock left
  servo.write(150);
  delay(500);
  leftDistance = getDistance();
  delay(100);
  servo.write(90);
  Serial.print("Left:");
  Serial.print(leftDistance);
  return leftDistance;
  delay(100);
}

int lookRight() {
  //lock right
  servo.write(30);
  delay(500);
  rightDistance = getDistance();
  delay(100);
  servo.write(90);
  Serial.print("   ");
  Serial.print("Right:");
  Serial.println(rightDistance);
  return rightDistance;
  delay(100);
}
void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

}
void turn() {
  if (object == true) {
    Serial.println("turn Left");
    moveLeft();
    delay(300);
    moveForward();
    delay(600);
    moveRight();
    delay(600);
    while(digitalRead(irCenter) == LineT_White){
      moveForward();
      delay(0.00001);
     }
     
      loop();
  }
  else {
    Serial.println("turn Right");
    moveRight();
    delay(300);
    moveForward();
    delay(600);
    moveLeft();
    delay(600);
    while(digitalRead(irCenter) == LineT_White){
      moveForward();
      delay(0.00001);
     }
      loop();
  }
}
void moveRight() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void moveLeft() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

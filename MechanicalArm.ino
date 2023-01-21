//CODE FOR MECHANICAL ARM
//Bhavjot Gill
#include <Servo.h>
//Declare and set variables
Servo servo1;
Servo servo2;
Servo servo3;
const int SW_pin = 2; 
const int X_pin = A0; 
const int Y_pin = A1; 
int sv=90;
int sv2=90;
int x;
int y;
int z=0;
int counter=1;
bool f=true;
void setup () {
//attach 3 servo motors to pins 9,10, and 11
servo1.attach (9) ;
servo2.attach (10) ;
servo3.attach (11) ;
//set the pushdown button in the joystick as a input and initialize it to high
pinMode (SW_pin, INPUT) ;
digitalWrite (SW_pin, HIGH) ;
Serial.begin (9600) ;
}
void loop (){
  //set initial position of servo 3 to 0
  servo3.write(0);
  //read and set values from joystick
 z=digitalRead(SW_pin);
 x=analogRead(X_pin) ;
 y=analogRead(Y_pin);
//increase and decrease values of servo based on input from joystick
 if (x<450&&sv>0){
  if(x>250){
    sv=sv-3;
  }
  else{
    sv=sv-5;
  }
 }
 if(x>550&&sv<180){
  if(x<750){
    sv=sv+3;
  }
  else{
    sv=sv+5;
  }
 }
 if(y<460&&sv2>0){
  if(y>250){
    sv2=sv2-3;
  }
  else{
    sv2=sv2-5;
  }
 }
 if(y>570&&sv2<75){
  if(y<750){
    sv2=sv2+3;
  }
  else{
    sv2=sv2+5;
  }
 }
if(z==0){
  counter++;
  delay(70);
}
//for clamping arm when joystick button is pressed down, when pressed it clamps and then when pressed gain it releases
//used module of 2 to track when its pressed
if(counter%2==0){
  servo3.write(70);
}
else{
  servo3.write(0);
}
 servo1.write(sv);
 servo2.write(sv2);
 delay(50);
}

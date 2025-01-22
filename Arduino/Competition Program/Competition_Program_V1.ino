

#include <PRIZM.h>    // TETRIX PRIZM library 
#include <TELEOP.h>   // TETRIX TeleOp module Library
#include <PULSE.h>    // TETRIX PULSE Library

EXPANSION exc;        // Create an instance whithin the EXPANSION Library class named exc
PULSE pulse;          // Create an instance within the PULSE Library class named pulse
PS4 ps4;              // Create an instance within the PS4 Library class named ps4

int Servo1 = 0;      // variables for servo channel set initially to 0
int Servo2 = 0;      // variables for servo channel set initially to 0
int Signal;

int PowerM1 = 999;          // Channel 1 Motor Power
int PowerM2 = 999;
int PowerM3 = 999;
int PowerM4 = 999;          // Channel 2 Motor Power

void setup() {


  pulse.PulseBegin();                 // Intializes the PULSE controller and waits here for press of green start button
  ps4.setDeadZone(LEFT, 5);           // Sets a Left Joystick Dead Zone axis range of +/- 5 about center stick. This eliminates servo jitter when joysticks are at center (neutral) position
  ps4.setDeadZone(RIGHT, 5);          // Sets a Right Joystick Dead Zone axis range of +/- 5 about center stick. This eliminates servo jitter when joysticks are at center (neutral) position
}

void loop() {

  ps4.getPS4();                                    // Get (read) PS4 connection status and all PS4 button and joystick data values

  Servo1 = ps4.Servo(R2T);                     // get the Left annalog trigger button value mapped to servo range
  pulse.setServoPosition(1, Servo1);

  Servo2 = ps4.Servo(L2T);                     // get the Right annalog trigger button value mapped to servo range
  pulse.setServoPosition(2, -Servo2);

  PowerM1=ps4.Motor(LY); 
      pulse.setMotorPower(2, -PowerM1); 
          //I made the ps4.motor command without the PowerM1=ps4.set blah blah to test if it changes the speed of the motors
  PowerM2=ps4.Motor(RY);                  // Power (speed) and direction of Motor 2 is set by position of Right Y-axis Joystick
      pulse.setMotorPower(1, PowerM2);
  PowerM3=ps4.Motor(LY);                  // Power (speed) and direction of Motor 2 is set by position of Right Y-axis Joystick
      exc.setMotorPower(1, 2, -PowerM3);
  PowerM4=ps4.Motor(RY); 
      exc.setMotorPower(1, 1, PowerM4); 
    
      delay(10);
  if(ps4.Connected != HIGH) {                                    // If PS4 is not connected, set Servo's to center position (40)
    pulse.setServoPosition(1,50);
    pulse.setServoPosition(2, 100);

  }
}
//Code made by Bry. (v0 made by Luna Bundy. v1 made by Bry with help from Miguel Riano fixing bugs)
//Praise the sun! and Fear the old blood, fellow traveler.

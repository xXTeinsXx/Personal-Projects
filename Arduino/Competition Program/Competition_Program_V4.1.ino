// This code was created and is used for controlling and running the SkillsUSA Robot.

// Import the libraries requiered to run the program and controll the TETRIX Boards
#include <PRIZM.h>    // TETRIX PRIZM Library 
#include <TELEOP.h>   // TETRIX TeleOp module Library
#include <PULSE.h>    // TETRIX PULSE Library

// Creating instances within the Library classes with their respective names
EXPANSION exc;         // Create an instance within the EXPANSION Library class named exc
PULSE pulse;          // Create an instance within the PULSE Library class named pulse
PS4 ps4;              // Create an instance within the PS4 Library class named ps4

// Stating all variables needed and giving them a set of values
int Servo1 = 0;      // variables for servo channel set initially to 0
int Power;          // Motor Power initially set to 999
int Claw = 0;         // Power for the Claw initially set to 0 degrees

// Setup code 
void setup() {
  pulse.PulseBegin();                 // Intializes the PULSE controller and waits here for press of green start button
  ps4.setDeadZone(LEFT, 5);           // Sets a Left Joystick Dead Zone axis range of +/- 5 about center stick. This eliminates servo jitter when joysticks are at center (neutral) position
  ps4.setDeadZone(RIGHT, 5);          // Sets a Right Joystick Dead Zone axis range of +/- 5 about center stick. This eliminates servo jitter when joysticks are at center (neutral) position
}

// Running code that takes in the inputs of the controller and outputs and motor control
void loop() {

  ps4.getPS4();                          // Get (read) PS4 connection status and all PS4 button and joystick data values

  ps4.Servo(R2T);                        // get the Left annalog trigger button value mapped to servo range
  pulse.setServoPosition(1, -Servo1);
 
// Controls Motors by using the right joystick
  Power = ps4.Motor(RY); 
      // Motor 1
      pulse.setMotorPower(1, Power);
      // Motor 2 
      exc.setMotorPower(1, 2, Power);

// Controls Motors by using the left joystick
  Power = ps4.Motor(LY);  
      // Motor 3
      pulse.setMotorPower(2, -Power);     // Power (speed) and direction of Motor 2 is set by position of Right Y-axis Joystick
      // Motor 4
      exc.setMotorPower(1, 1,  -Power);

      delay(10);

  if(ps4.Connected != HIGH) {
    // If PS4 is not connected, set Servo's to center position (100)
    pulse.setServoPosition(1,50);
    pulse.setServoPosition(2, 100);
  }
}
//Competition Robot code v4.1. Code written by Bryan. Robot worked on by Jonathan, Armani and Bry. Praise the Sun, and may the Old Blood guide you!

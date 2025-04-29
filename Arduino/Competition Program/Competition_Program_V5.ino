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
int PowerM1;         // Motor 1 Power variable
int PowerM2;         // Motor 2 Power variable
int PowerM3;         // Motor 3 Power variable (Arm motor)
int Claw = 0;        // Power for the Claw initially set to 0 degrees

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
  pulse.setServoPosition(1, -Servo1);    // Set servo position based on trigger value
 
  // Controls Motors by using the right joystick
  PowerM1 = ps4.Motor(LY); 
      // Motor 1
      pulse.setMotorPower(1, -PowerM1);  // Set power for Motor 1 based on left joystick Y-axis
      // Motor 2 
      exc.setMotorPower(1, 2, -PowerM1); // Set power for Motor 2 based on left joystick Y-axis

  // Controls Motors by using the left joystick
  PowerM2 = ps4.Motor(RY);  
      // Motor 3
      pulse.setMotorPower(2, PowerM2);    // Power (speed) and direction of Motor 3 is set by position of Right Y-axis Joystick
      // Motor 4
      exc.setMotorPower(1, 1, PowerM2);   // Power (speed) and direction of Motor 4 is set by position of Right Y-axis Joystick

  // Controls the arm Motor using the D-pad UP and DOWN buttons
  if (ps4.Button(UP)) {                  // If D-pad UP button is pressed
    exc.setMotorPower(2, 1, 100);        // Arm Motor moves up at full power
  } 
  else if (ps4.Button(DOWN)) {           // If D-pad DOWN button is pressed
    exc.setMotorPower(2, 1, -100);       // Arm Motor moves down at full power
  }
  else {
    exc.setMotorPower(2, 1, 0);          // Stop the arm motor when no buttons are pressed
  }

  delay(10);                             // Small delay for system stability

  // Safety code for when controller is disconnected
  if(ps4.Connected != HIGH) {
    // If PS4 is not connected, set Servo's to center position (100)
    pulse.setServoPosition(1, 50);
    pulse.setServoPosition(2, 100);
    
    // Also stop all motors for safety
    pulse.setMotorPower(1, 0);
    pulse.setMotorPower(2, 0);
    exc.setMotorPower(1, 1, 0);
    exc.setMotorPower(1, 2, 0);
    exc.setMotorPower(2, 1, 0);
  }
}
//Competition Robot code v6. Code written by Bryan. Robot worked on by Jonathan, Armani and Bry. Praise the Sun, and may the Old Blood guide you!
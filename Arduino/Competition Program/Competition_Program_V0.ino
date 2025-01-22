


#include <TELEOP.h>   // TETRIX TeleOp module Library
#include <PULSE.h>    // TETRIX PULSE Library

PULSE pulse;          // Create an instance within the PULSE Library class named pulse
PS4 ps4;              // Create an instance within the PS4 Library class named ps4

int Servo1 = 100;      // variables for servo channel set initially to 40
int Servo2 = 90;      // variables for servo channel set initially to 90
int Servo3 = 40;
int Servo4 = 40;

int PowerM1;          // Channel 1 Motor Power
int PowerM2;          // Channel 2 Motor Power

void setup() {

  pulse.PulseBegin();                 // Intializes the PULSE controller and waits here for press of green start button

  pulse.setServoPosition(1, Servo1);  // send servo to position 40 on program begin
  pulse.setServoPosition(2, Servo2);  // send servo to position 90 on program begin
  pulse.setServoPosition(3, Servo3);
  pulse.setServoPosition(4, Servo4);

  ps4.setDeadZone(LEFT, 5);           // Sets a Left Joystick Dead Zone axis range of +/- 5 about center stick. This eliminates servo jitter when joysticks are at center (neutral) position
  ps4.setDeadZone(RIGHT, 5);          // Sets a Right Joystick Dead Zone axis range of +/- 5 about center stick. This eliminates servo jitter when joysticks are at center (neutral) position

}

void loop() {
  ps4.getPS4();                                   // "last command on the startup goes here" Get (read) PS4 connection status and all PS4 button and joystick data values

  if (ps4.Connected) {                            // If PS4 controller has been succesfully connected, control servo motor
  Servo1 = ps4.Servo(R2T);                     // get the Left annalog trigger button value mapped to servo range
  pulse.setServoPosition(1, Servo1);

  Servo2 = ps4.Servo(L2T);                     // get the Right annalog trigger button value mapped to servo range
  pulse.setServoPosition(2, Servo2);

  if (ps4.Connected) {                          // If PS4 controller has been succesfully connected, control motors

    PowerM1 = ps4.Motor(LY);
      pulse.setMotorPowers(-900,900);               // Power (speed) and direction of Motor 1 is set by position of Left Y-axis Joystick
    PowerM2 = ps4.Motor(RY);                  // Power (speed) and direction of Motor 2 is set by position of Right Y-axis Joystick

    Serial.println(PowerM1);
  }
  else {                                        // If PS4 is not connected, set Servo's to center position (40)
    pulse.setServoPosition(1, 40);
    pulse.setServoPosition(2, 40);

  }
}

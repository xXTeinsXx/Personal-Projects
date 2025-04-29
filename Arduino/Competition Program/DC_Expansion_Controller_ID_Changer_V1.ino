/**************************************
 * DC Motor Expansion Controller ID Changer
 * 
 * This utility program reads the current ID
 * of a TETRIX DC Motor Expansion Controller 
 * and changes it to ID #2
 **************************************/

#include <PRIZM.h>      // Include the PRIZM library for TETRIX robotics controller functions

PRIZM prizm;            // Instantiate the PRIZM object for controlling the PRIZM board
EXPANSION exc;

void setup() {
  
  Serial.begin(9600);   // Initialize serial communication at 9600 bps for debugging output
  prizm.PrizmBegin();   // Initialize the PRIZM controller and enable all control features
  
  // Print a header to the serial monitor
  Serial.println("DC Motor Expansion Controller ID Change Utility");
  Serial.println("--------------------------------------------");
  
  // Read the current ID of the connected expansion controller
  // Note: Only one expansion controller should be connected during this operation
  int currentID = exc.readExpID();
  Serial.print("Current Expansion Controller ID: ");
  Serial.println(currentID);
  
  // Change the ID to 2
  // Valid IDs are 1-4 according to the TETRIX PRIZM Arduino Library
  Serial.println("Changing ID to 2...");
  exc.setExpID(2);
  Serial.println("ID has been changed to 2.");
  
  // Notify user about power cycling requirement
  // Changes to the ID take effect only after power cycling the controller
  Serial.println("Power cycle the expansion controller for changes to take effect.");
  
  prizm.PrizmEnd();     // End PRIZM - disables all control functions
}

void loop() {
  // Nothing needed in loop for this utility program
  // The program completes its task in setup() and doesn't need to repeat
}

/*
 * Written by Bryan Caban
 * Last updated: April 23, 2025
 * 
 * This program changes the ID of a TETRIX DC Motor Expansion Controller
 * from its default value to ID #2, allowing multiple controllers to be 
 * daisy-chained without address conflicts.
 */
/**********************************************
 * TETRIX DC Motor Expansion Controller Info Reader
 * 
 * This utility program detects connected DC Motor
 * Expansion Controllers and displays comprehensive
 * information about each device including:
 * - Firmware version
 * - Controller ID
 * - Battery voltage
 * - Motor status
 * - Encoder readings
 * - Current PID settings
 **********************************************/

#include <PRIZM.h>      // Include the PRIZM library for TETRIX robotics controller functions

PRIZM prizm;            // Instantiate the PRIZM object for controlling the PRIZM board
EXPANSION exc;          // Instantiate the EXPANSION object for expansion controller functions

// Function prototypes
void displayControllerInfo(int id);
void displayEncoderInfo(int id);
void displayMotorInfo(int id);
void displayPIDSettings(int id);
float getBatteryVoltage(int id);

void setup() {
  Serial.begin(9600);   // Initialize serial communication at 9600 bps for output
  prizm.PrizmBegin();   // Initialize the PRIZM controller and enable all control features
  
  // Print the header to the serial monitor
  Serial.println("=================================================");
  Serial.println("   TETRIX DC Motor Expansion Controller Scanner");
  Serial.println("=================================================");
  Serial.println("Scanning for connected expansion controllers...");
  
  // Scan for controllers with IDs 1-4 (maximum supported by PRIZM)
  boolean foundAny = false;
  
  for (int id = 1; id <= 4; id++) {
    // Try to read firmware version to determine if controller exists
    uint8_t fwVersion = exc.readDCFirmware(id);
    
    // If we get a non-zero response, a controller is connected with this ID
    if (fwVersion > 0) {
      foundAny = true;
      Serial.print("\n>> Found DC Motor Expansion Controller with ID #");
      Serial.println(id);
      
      // Display comprehensive information about this controller
      displayControllerInfo(id);
      displayMotorInfo(id);
      displayEncoderInfo(id);
      displayPIDSettings(id);
      
      Serial.println("-------------------------------------------------");
    }
  }
  
  if (!foundAny) {
    Serial.println("\nNo DC Motor Expansion Controllers detected!");
    Serial.println("\nPossible issues:");
    Serial.println("- Check power connections");
    Serial.println("- Verify data cable is properly connected");
    Serial.println("- Ensure controllers have unique IDs");
  }
  
  Serial.println("\nScan complete. To run again, reset the PRIZM controller.");
}

void loop() {
  // This is a one-time utility program, main functionality is in setup()
  delay(1000);
}

/**
 * Displays general information about the controller
 */
void displayControllerInfo(int id) {
  // Read and display firmware version
  uint8_t fwVersion = exc.readDCFirmware(id);
  Serial.print("  Firmware Version: ");
  Serial.println(fwVersion);
  
  // Read and display battery voltage
  float voltage = getBatteryVoltage(id);
  Serial.print("  Battery Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  
  if (voltage < 11.0) {
    Serial.println("  ** WARNING: Battery voltage is low! **");
  }
}

/**
 * Displays information about the motors connected to the controller
 */
void displayMotorInfo(int id) {
  Serial.println("\n  MOTOR STATUS:");
  Serial.println("  ------------");
  
  // For each motor channel
  for (int motor = 1; motor <= 2; motor++) {
    Serial.print("  Motor ");
    Serial.print(motor);
    Serial.println(":");
    
    // Read and display current
    int current = exc.readMotorCurrent(id, motor);
    Serial.print("    Current: ");
    Serial.print((float)current/1000.0, 2);  // Convert from mA to A
    Serial.println(" A");
    
    // Read and display busy status
    int busy = exc.readMotorBusy(id, motor);
    Serial.print("    Busy Status: ");
    Serial.println(busy ? "BUSY (moving to target)" : "IDLE");
  }
}

/**
 * Displays information about the encoders connected to the controller
 */
void displayEncoderInfo(int id) {
  Serial.println("\n  ENCODER READINGS:");
  Serial.println("  ----------------");
  
  // For each encoder channel
  for (int enc = 1; enc <= 2; enc++) {
    Serial.print("  Encoder ");
    Serial.print(enc);
    Serial.println(":");
    
    // Read and display count
    long count = exc.readEncoderCount(id, enc);
    Serial.print("    Count: ");
    Serial.println(count);
    
    // Read and display degrees
    long degrees = exc.readEncoderDegrees(id, enc);
    Serial.print("    Degrees: ");
    Serial.println(degrees);
  }
}

/**
 * Gets the current PID settings from the controller
 * Note: The actual PID coefficients cannot be read from the controller
 * This displays the default values from the documentation
 */
void displayPIDSettings(int id) {
  Serial.println("\n  PID SETTINGS (Default Values):");
  Serial.println("  ---------------------------");
  Serial.println("  Constant Speed PID:");
  Serial.println("    P = 1.5");
  Serial.println("    I = 2.5");
  Serial.println("    D = 0.008");
  
  Serial.println("  Target Position PID:");
  Serial.println("    P = 1.5");
  Serial.println("    I = 0");
  Serial.println("    D = 0.005");
  
  Serial.println("\n  Note: Custom PID values can be set but cannot be read back");
}

/**
 * Reads the battery voltage and returns it as a float value
 */
float getBatteryVoltage(int id) {
  int rawVoltage = exc.readBatteryVoltage(id);
  return (float)rawVoltage / 100.0;  // Convert from raw value to actual voltage
}

/*
 * Created on April 23, 2025
 * Based on TETRIX DC Motor Expansion Controller documentation 
 * and sample code by Bryan Caban
 *
 * This program scans for and displays comprehensive information
 * about connected TETRIX DC Motor Expansion Controllers.
 */
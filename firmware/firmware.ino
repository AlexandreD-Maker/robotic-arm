/**
 * @file firmware.ino
 * @brief Manual control of the servo motors using potentiometers
 * 
 * Each of the 5 potentiometers is assigned to a servo
 */

#include "config.h"
#include "motors.h"
#include "control.h"

void setup() {

    initMotors();

}

void loop() {
    
    readPot();
    for(int i = 0; i < NUMBER_MOTOR; i++) {
        moveMotor(Joint(i), motorAngle[i]);
    }

}
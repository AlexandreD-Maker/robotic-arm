/**
 * @file firmware.ino
 * @brief Main firmware entry point for the robotic arm
 *
 * This file contains the setup() and loop() functions and acts
 * as the central coordinator of the robotic arm firmware
 *
 * The firmware supports two control modes:
 * - Manual mode: joint angles are controlled using potentiometers
 * - Code-controlled mode: joint angles are received via serial commands
 *
 * A safety mechanism is implemented when switching from code-controlled mode to
 * manual mode to prevent sudden motor movements. Before enabling manual control,
 * potentiometer positions must match the current motor angles within an acceptable tolerance
 *
 * Visual feedback is provided through a status LED:
 * - LED ON: code-controlled mode active
 * - LED BLINKING: potentiometer synchronization required
 * - LED OFF: manual mode active
 *
 */

#include "config.h"
#include "motors.h"
#include "control.h"
#include "mode_switching.h"

void setup() {
    pinMode(FEEDBACK_LED_PIN, OUTPUT);
    // INPUT_PULLUP is set to use the internal resistor of Arduino
    pinMode(MODE_SWITCHING_BUTTON_PIN, INPUT_PULLUP);
    initMotors();
    Serial.begin(9600);
}

void loop() {
        if(mode == MANUAL) {
            readPot();
            for(uint8_t i = 0; i < NUMBER_MOTOR; i++) {
                moveMotor(Joint(i), motorAngle[i]);
            }
        }
        else {
            if(Serial.available() > 0) {
                readUserInput();
            }
            
            for(uint8_t i = 0; i < NUMBER_MOTOR; i++) {
                if(userAngle[i] != -1) {
                    moveMotor(Joint(i), userAngle[i]);
                }
                
            }
        }
        
    if(digitalRead(MODE_SWITCHING_BUTTON_PIN) == 0) {
        delay(250);
        if(mode == CODE_CONTROL) {
            syncPot();
        }
        else {
            for(uint8_t i = 0; i < NUMBER_MOTOR; i++) {
                userAngle[i] = motorAngle[i];
            }
        }
        switchMode();
    }    
    
}

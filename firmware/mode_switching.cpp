#include "config.h"
#include "control.h"

bool mode = MANUAL;
uint8_t userAngle[NUMBER_MOTOR];
uint8_t angleTolerance = 3;

void blinkLed() {
    digitalWrite(FEEDBACK_LED_PIN, LOW);
    delay(150);
    digitalWrite(FEEDBACK_LED_PIN, HIGH);
    delay(150);
}

void syncPot() {
    for(uint8_t i = 0; i < NUMBER_MOTOR; i++) {
        // Check if potentiometer angle is more or less 3° the current angle
        if(abs(motorAngle[i] - userAngle[i]) > angleTolerance) {
            Serial.println("Please set potentiometers to the current position");
        }
        while(abs(motorAngle[i] - userAngle[i]) > angleTolerance) {
            blinkLed();
            readPot();
            Serial.print("Potentiometer angle: "); Serial.print(motorAngle[i]);
            Serial.print(" Motor angle: "); Serial.println(userAngle[i]);
            delay(250);
        }
        
    }
    
}
void switchMode() {
    if(mode == MANUAL) {
        mode = CODE_CONTROL;
        digitalWrite(FEEDBACK_LED_PIN, HIGH);
        Serial.println("Mode switched to code control");
    }

    else {
        digitalWrite(FEEDBACK_LED_PIN, LOW);
        mode = MANUAL;
        Serial.println("Mode switched to manual control");
    }
}
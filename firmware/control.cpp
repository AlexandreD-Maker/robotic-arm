#include "config.h"
#include "control.h"
#include "motors.h"

uint8_t motorAngle[NUMBER_MOTOR];

uint8_t potPin[NUMBER_MOTOR] = {
    BASE_POT_PIN,
    SHOULDER_POT_PIN,
    ELBOW_POT_PIN,
    WRIST_POT_PIN,
    GRIPPER_POT_PIN
};

void readPot() {
    for(uint8_t i = 0; i < NUMBER_MOTOR; i++) {
        motorAngle[i] = map(analogRead(potPin[i]), 0, 1023, 0, 180);
    }
}
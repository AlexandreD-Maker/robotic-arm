#include "config.h"
#include "motors.h"

Servo motors[NUMBER_MOTOR];

uint8_t motorPin[NUMBER_MOTOR] = {
    BASE_MOTOR_PIN,
    SHOULDER_MOTOR_PIN,
    ELBOW_MOTOR_PIN,
    WRIST_MOTOR_PIN,
    GRIPPER_MOTOR_PIN
};

void initMotors() {
    for(uint8_t i = 0; i < NUMBER_MOTOR; i++) {
        motors[i].attach(motorPin[i]);
    }
}

void moveMotor(Joint motor, uint8_t angle) {
        motors[motor].write(angle);
}
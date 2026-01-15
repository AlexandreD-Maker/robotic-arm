#include "config.h"
#include "motors.h"

Servo motors[5];

void initMotors() {
    motors[BASE].attach(BASE_MOTOR_PIN);
    motors[SHOULDER].attach(SHOULDER_MOTOR_PIN);
    motors[ELBOW].attach(ELBOW_MOTOR_PIN);
    motors[WRIST].attach(WRIST_MOTOR_PIN);
    motors[GRIPPER].attach(GRIPPER_MOTOR_PIN);
}

void moveMotor(uint8_t motor, uint8_t angle) {
        motors[motor].write(angle);
}
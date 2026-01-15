#include "config.h"
#include "control.h"
#include "motors.h"

uint8_t motorAngle[5];

void readPot() {
    motorAngle[BASE] = map(analogRead(BASE_POT_PIN), 0, 1023, 0, 180);
    motorAngle[SHOULDER] = map(analogRead(SHOULDER_POT_PIN), 0, 1023, 0, 180);
    motorAngle[ELBOW] = map(analogRead(ELBOW_POT_PIN), 0, 1023, 0, 180);
    motorAngle[WRIST] = map(analogRead(WRIST_POT_PIN), 0, 1023, 0, 180);
    motorAngle[GRIPPER] = map(analogRead(GRIPPER_POT_PIN), 0, 1023, 0, 180);
}
/**
 * @file motors.h
 * @brief Interface for servo motor control
 *
 * Provides functions to initialize and control the robotic arm joints using servos.
 *
 */

#pragma once
#include <Servo.h>

extern Servo motors[NUMBER_MOTOR];

void initMotors();
void moveMotor(Joint motor, uint8_t angle);
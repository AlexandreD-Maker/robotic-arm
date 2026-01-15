/**
 * @file motors.h
 * @brief Interface for servo motor control
 *
 * Provides functions to initialize and control the robotic arm joints using servos.
 *
 */

#pragma once
#include <Servo.h>

extern Servo motors[5];

void initMotors();
void moveMotor(uint8_t motor, uint8_t angle);
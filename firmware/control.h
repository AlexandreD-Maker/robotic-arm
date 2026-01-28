/**
 * @file control.h
 * @brief Interface between user input and motor commands
 *
 * Provides functions to get user inputs (potentiometers or serial commands)
 * and translate it to target motor angles
 *
 * It reads, parses, and validates user inputs but doesn't directly control the motors
 */

#pragma once
#include "config.h"

extern uint8_t motorAngle[NUMBER_MOTOR];
extern String userInput[NUMBER_MOTOR];

void readPot();
void readUserInput();
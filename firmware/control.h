/**
 * @file control.h
 * @brief Interface between user input and motor commands
 *
 * Provides functions to get user input and translate it to motor commands
 *
 */

#pragma once
#include "config.h"

extern uint8_t motorAngle[5];

void readPot();
/**
 * @file mode_switching.h
 * @brief Control mode management and safety handling
 *
 * Handles switching between manual and code-controlled modes
 * 
 * Ensures safe transitions by synchronizing potentiometer positions
 * with current motor angles when required
 * 
 * Visual feedback is provided using an LED to indicate the current control mode
 * and synchronization state
 * 
 */


#pragma once
#include "config.h"
#include "control.h"

extern bool mode;
extern bool button_state;
extern uint8_t userAngle[NUMBER_MOTOR];

/**
 * @brief Synchronize potentiometers with current motor positions
 *
 * Prevents sudden motor jumps when returning to manual control by ensuring
 * that potentiometer values match motor angles within an acceptable tolerance
 */
void syncPot();

/**
 * @brief Switch between control modes
 *
 * Toggles the current control mode and applies the required safety
 * procedures when transitioning from code-controlled to manual mode
 */
void switchMode();
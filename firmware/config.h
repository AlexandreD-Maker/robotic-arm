/**
 * @file config.h
 * @brief Global configuration and system definitions
 * 
 * This file centralizes all hardware mappings, system-wide constants, and shared enumeration used by the robotic arm firmware
 * 
 */

#pragma once
#include <Arduino.h>

const uint8_t NUMBER_MOTOR = 5;

// Motor pins (PWM capable)
const uint8_t BASE_MOTOR_PIN = 3;
const uint8_t SHOULDER_MOTOR_PIN = 5;
const uint8_t ELBOW_MOTOR_PIN = 6;
const uint8_t WRIST_MOTOR_PIN = 9;
const uint8_t GRIPPER_MOTOR_PIN = 10;

// Potentiometer pins (analog)
const uint8_t BASE_POT_PIN = A0;
const uint8_t SHOULDER_POT_PIN = A1;
const uint8_t ELBOW_POT_PIN = A2;
const uint8_t WRIST_POT_PIN = A3;
const uint8_t GRIPPER_POT_PIN = A4;

// Mode switching pins
const uint8_t FEEDBACK_LED_PIN = 2;
const uint8_t MODE_SWITCHING_BUTTON_PIN = 4;

// Joint indices
enum Joint {
    BASE = 0,
    SHOULDER,
    ELBOW,
    WRIST,
    GRIPPER
};
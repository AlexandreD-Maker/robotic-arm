/**
 * @file firmware.ino
 * @brief Manual control of the servo motors using potentiometers
 * 
 * Each of the 5 potentiometers is assigned to a servo
 */

#include <Servo.h>

// The motor pins are chosen for their PWM capability
int base_motor_pin = 3;
int shoulder_motor_pin = 5;
int elbow_motor_pin = 6;
int wrist_motor_pin = 9;
int gripper_motor_pin = 10;

int base_motor_pot = A0;
int shoulder_motor_pot = A1;
int elbow_motor_pot = A2;
int wrist_motor_pot = A3;
int gripper_motor_pot = A4;

Servo base_motor;
Servo shoulder_motor;
Servo elbow_motor;
Servo wrist_motor;
Servo gripper_motor;

int base_motor_pos;
int shoulder_motor_pos;
int elbow_motor_pos;
int wrist_motor_pos;
int gripper_motor_pos;

void print_motor_angle(char* motor, int motor_angle) {
    Serial.print(motor);
    Serial.print("motor: ");
    Serial.println(motor_angle);
}
void setup() {
    base_motor.attach(base_motor_pin);
    shoulder_motor.attach(shoulder_motor_pin);
    elbow_motor.attach(elbow_motor_pin);
    wrist_motor.attach(wrist_motor_pin);
    gripper_motor.attach(gripper_motor_pin);

    Serial.begin(9600);
}

void loop() {
    base_motor_pos = map(analogRead(base_motor_pot), 0, 1023, 0, 180);
    shoulder_motor_pos = map(analogRead(shoulder_motor_pot), 0, 1023, 0, 180);
    elbow_motor_pos = map(analogRead(elbow_motor_pot), 0, 1023, 0, 180);
    wrist_motor_pos = map(analogRead(wrist_motor_pot), 0, 1023, 0, 180);
    gripper_motor_pos = map(analogRead(gripper_motor_pot), 0, 1023, 0, 180);

    base_motor.write(base_motor_pos);
    shoulder_motor.write(shoulder_motor_pos);
    elbow_motor.write(elbow_motor_pos);
    wrist_motor.write(wrist_motor_pos);
    gripper_motor.write(gripper_motor_pos);

    print_motor_angle("base", base_motor_pos);
    print_motor_angle("shoulder", shoulder_motor_pos);
    print_motor_angle("elbow", elbow_motor_pos);
    print_motor_angle("wrist", wrist_motor_pos);
    print_motor_angle("gripper", gripper_motor_pos);
    Serial.println();
    
}

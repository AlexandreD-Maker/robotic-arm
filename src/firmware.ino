#include <Servo.h>

int base_motor_pin = 3;
int shoulder_motor_pin = 5;
int elbow_motor_pin = 6;
int wrist_motor_pin = 9;
int gripper_motor_pin = 10;

Servo base_motor;
Servo shoulder_motor;
Servo elbow_motor;
Servo wrist_motor;
Servo gripper_motor;

void setup() {
    base_motor.attach(base_motor_pin);
    shoulder_motor.attach(shoulder_motor_pin);
    elbow_motor.attach(elbow_motor_pin);
    wrist_motor.attach(wrist_motor_pin);
    gripper_motor.attach(gripper_motor_pin);

    Serial.begin(9600);
}

void loop() {

}

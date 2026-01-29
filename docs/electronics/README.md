# Electronics

This folder contains the electronic design of the robotic arm, including the schematic, power architecture, and design rationale behind key technical decisions.


---
## System Overview

The electronic system is responsible for:
- Reading user inputs through potentiometers
- Generating PWM signals for servo motor control
- Distributing power safely between logic and actuators
- Ensuring stable electrical references across the system

The architecture separates logic power and actuator power to improve reliability.

---
## Main Components

- **Microcontroller**  
  Arduino UNO R3 board used for:
  - Analog input acquisition
  - PWM signal generation
  - High-level control logic

- **Actuators**
  - 3 × MG996R servo motors (base, shoulder, elbow)
  - 2 × SG90 servo motors (wrist, gripper)

- **User Inputs**
  - Potentiometers connected to analog inputs

- **Power Supply**
  - External 5V / 4A DC supply dedicated to servos
  - USB power for the microcontroller

---
## Power Architecture and Design Rationale

Servo motors are powered by an external 5V supply to avoid voltage drops, noise injection, and brownouts on the microcontroller power rail.

The power supply was dimensioned based on:
- Typical current consumption of each servo during motion
- Realistic operating scenarios where not all servos are simultaneously stalled
- An additional safety margin suitable for a prototype system

This approach provides sufficient current capacity for normal operation while keeping the system simple and easy to scale.

All grounds (external power supply and microcontroller ground) are tied together to ensure correct signal referencing for PWM and analog inputs.

---
## Analog Input Strategy

Potentiometers are powered from the microcontroller 5V rail and connected to analog input pins.

This ensures:
- A stable reference voltage
- Consistent readings independent of servo power fluctuations
- Signal integrity

---
## Schematic

An overview of the circuit diagram is shown below:

![Circuit diagram overview](../../assets/electronics/circuit_diagram.png)

The complete schematic is also available as a PDF in this directory for detailed inspection.

---
## Tools

- **Schematic design**: KiCad 9.0.6


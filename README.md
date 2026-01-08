# Robotic arm project

This repository contains the complete development of my custom robotic arm project, covering mechanical design, embedded control, and system-level integration.

It includes:

- Arduino code
- CAD designs
- Electrical schematic
- Documentation (Github Pages)
---

## Design evolution
This project started as a manually controlled 4-DOF robotic arm using potentiometers, and was progressively extended toward a more structured and testable control architecture.

The evolution focuses on improving motion reproducibility, control clarity, and system testability.

---

## Global architecture

The robotic arm can be controlled using two control modes:
- **Manual mode:** Direct joint control using potentiometers
- **Code-controlled mode:** Joint position commands are sent via the serial interface, allowing reproducible and testable movements. A feedback LED indicates when this mode is active.

The system starts in manual mode by default.

A push button allows safe switching between control modes.

---

## 🚧 Project status

This project is currently under development.

Ongoing work includes:
- CAD design and assembly validation
- development of the control algorithm
- creation and expansion of the technical documentation.
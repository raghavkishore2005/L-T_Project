# L-T_Project

# Real-Time Occupancy Detection System

This project implements a microcontroller-based real-time occupancy detection system that monitors motion through a room's entry point and automatically controls electrical appliances such as fans and lights to improve energy efficiency.

## Overview

The prototype is built using two PIR motion sensors placed at the room's entrance to detect human entry and exit. Based on the motion detected, the system determines whether the room is occupied. If no movement is detected for a specified cooldown period after exit, it turns off connected appliances to conserve power.

## Objective

To design and simulate an automated system that detects the presence or absence of people in a room in real-time and switches off unnecessary electrical loads when the room is unoccupied.

## Scope

This system is applicable for smart homes, office cabins, classrooms, and other indoor environments where energy conservation is essential. It is scalable and can be integrated with cloud-based IoT platforms for remote monitoring and control.

## Hardware Used

* Arduino Nano 33 IoT / Arduino UNO
* PIR Motion Sensors (2 units)
* Red LEDs (2 units for Fan and Light indicators)
* Resistors (2 × 1kΩ)
* Breadboard / Custom PCB
* Jumper wires
* USB cable for programming and power

## Software Tools

* Arduino IDE
* TinkerCad (for circuit simulation)
* EasyEDA (for schematic design and Gerber generation)
* GitHub (for version control and submission)

## Project Implementation

The circuit uses two PIR motion sensors to detect movement. One is placed facing outward from the room (entry sensor), and the other faces inward (exit sensor). When both sensors are triggered in sequence, it is interpreted as a person entering or exiting.

If a person enters, the system turns on the fan and light (represented by LEDs). When a person exits, a 30-second countdown timer begins. If no motion is detected during this cooldown period, the fan and light are automatically turned off.

## Results

The system successfully detects entries and exits through the doorway and controls the fan and light accordingly. The LEDs accurately reflect the status of appliances. The logic is implemented efficiently using non-blocking code with `millis()`, and the entire setup is validated both through simulation and schematic design.

## Files Included

* Arduino code: `occupancy_detector.ino`
* TinkerCad circuit image: `tinkercad_circuit.png`
* EasyEDA schematic: `easyeda_schematic.png`
* Gerber ZIP file for PCB: `Occupancy_Detection_Gerber.zip`
* Project report: `report.pdf`
* Demo video: `demo.mp4` (if recorded)

## Conclusion

This real-time occupancy detection prototype demonstrates an effective method for automating room appliances based on presence detection. It contributes toward energy-efficient smart systems and forms the basis for further IoT-enabled automation solutions.


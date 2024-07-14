# Omnidirectional Robot Control with PS4 Controller

![Robot](https://github.com/mike37510/OmnidirectionalRobot/blob/main/448396422_1244862013344547_5515443539340075409_n.jpg)

## Introduction
Brief overview of the project and its objectives.

### Features
- Control of an omnidirectional robot using a PS4 controller.
- Integration of motors, ESP32 microcontroller, and PS4 communication.

## Hardware Requirements
List of components needed to replicate the project.

- ESP32 microcontroller
- Four omnidirectional wheels with DC motors
- L298N motor drivers (2 units)
- PS4 controller
- LIPO battery pack
- Connecting wires

## Software Requirements
Dependencies and libraries required to run the project.

- PS4Controller library for Arduino IDE
- ESP32 board package for Arduino IDE

## Installation Instructions
Step-by-step guide on how to set up the project environment.

1. **Hardware Setup:**
   - Connect IN1, IN2, IN3, and IN4 of the motor driver to GPIO pins 16, 17, 18, and 19 of the ESP32, respectively.
   - Connect IN5, IN6, IN7, and IN8 of the motor driver to GPIO pins 25, 26, 27, and 32 of the ESP32, respectively.
   - Connect ENA and ENB of the motor driver to GPIO pins 14 and 12 of the ESP32.
   - Connect ENA2 and ENB2 of the motor driver to GPIO pins 15 and 2 of the ESP32.
   - Connect the motors to the outputs of the motor driver.

2. **Software Setup:**
   - Install necessary libraries in Arduino IDE (PS4Controller and ESP32 board package).
   - Upload the provided Arduino sketch to the ESP32.

## Usage
Instructions on how to use the robot with the PS4 controller.

1. **Pairing PS4 Controller:**
   - Obtain the MAC address of your PS4 controller.
   - Update the MAC address in the Arduino sketch.
   - Power on the PS4 controller and ESP32, then establish connection.

2. **Controlling the Robot:**
   - Use the left stick for forward/backward motion and right stick for rotation.
   - L2 trigger for left lateral movement and R2 trigger for right lateral movement.

## Code Explanation
Detailed breakdown of the Arduino sketch functionality.

- **Setup Function:** Initializes GPIO pins and establishes PS4 controller connection.
- **Loop Function:** Continuously monitors PS4 controller inputs and adjusts motor speeds accordingly.
- **Motor Control Functions:** Detailed description of functions for forward, backward, lateral, and rotational movements.

## Enhancements
Suggestions for expanding and improving the project.

- Adding sensors for obstacle avoidance.
- Integrating with external systems or platforms.
- Optimizing control logic for specific applications.

## Additional Features
Description of optional components added to the robot.

- **FPV Camera and VTX Module:** Provides live video feedback to a FPV headset.

## Resources
Links to external resources, such as:
- PS4Controller library GitHub repository
- ESP32 board package installation guide

## Conclusion
Final thoughts on the project and encouragement for further exploration.
More informations : https://www.borninthe80s.fr/2024/06/29/conception-de-mon-robot-a-roues-omnidirectionnels/ and https://www.borninthe80s.fr/2024/07/14/conception-de-mon-robot-a-roues-omnidirectionnels-partie-2/

## Support
Instructions for seeking help or contributing to the project.

- Issues: Report any bugs or problems.
- Pull Requests: Submit improvements or new features.

## License
Information about the project's licensing.

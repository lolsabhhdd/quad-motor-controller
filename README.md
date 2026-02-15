# Quad Motor Controller for Arduino

## Overview
Control 4 DC motors with adjustable speed using Arduino. Each motor drives a circular disk (wheel) and all motors rotate clockwise simultaneously.

## Hardware Requirements
- Arduino Uno
- 4 DC Motors
- 4 PWM pins (3, 5, 6, 9)
- Motor Driver Module (L298N)
- 4 Wheels/Disks
- Power supply

## Pin Configuration
- Motor 1: Pin 3 (PWM)
- Motor 2: Pin 5 (PWM)
- Motor 3: Pin 6 (PWM)
- Motor 4: Pin 9 (PWM)

## Speed Control
- Range: 0-255
- 0 = Motor OFF
- 255 = Maximum speed

## Main Functions

### setAllMotorSpeeds(speed1, speed2, speed3, speed4)
Set all motors to specific speeds.
Example: `setAllMotorSpeeds(150, 150, 150, 150);`

### runAllMotors()
Apply current speed settings to all motors.

### stopAllMotors()
Stop all motors immediately.

### increaseSpeed(increment)
Increase speed by value.
Example: `increaseSpeed(20);`

### decreaseSpeed(decrement)
Decrease speed by value.
Example: `decreaseSpeed(20);`

## Wiring

# Line Following Robot — Arduino + IR Sensors

An autonomous robot that detects and follows a black line on a white surface using two IR sensors. The robot makes real-time decisions based on sensor input — no human control required.

## Built By
Muhammad Fakhir — Computer Science Student, University of Lahore  
GitHub: [github.com/fakhirsz](https://github.com/fakhirsz)

## Hardware Used
| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| IR Sensor Module | 2 |
| L298N Motor Driver | 1 |
| DC Gear Motors | 2 |
| Robot Chassis (2WD) | 1 |
| AA Battery Pack | 1 |
| Jumper Wires | As needed |

## How It Works
| Left Sensor | Right Sensor | Action |
|---|---|---|
| LOW (on line) | LOW (on line) | Move Forward |
| LOW (on line) | HIGH (off line) | Turn Left |
| HIGH (off line) | LOW (on line) | Turn Right |
| HIGH (off line) | HIGH (off line) | Stop |

- IR sensors output LOW when they detect a black line
- Arduino reads both sensors every loop cycle
- Based on the combination, it drives the motors accordingly
- PWM speed control allows smooth turning vs full-speed straight movement

## Circuit Connections
| Component | Arduino Pin |
|---|---|
| Left IR Sensor | D8 |
| Right IR Sensor | D9 |
| L298N IN1 | D2 |
| L298N IN2 | D3 |
| L298N ENA | D5 (PWM) |
| L298N IN3 | D4 |
| L298N IN4 | D7 |
| L298N ENB | D6 (PWM) |

## Skills Demonstrated
- Autonomous decision-making logic
- Digital sensor input reading
- Arduino C++ programming
- DC motor control via L298N
- Embedded systems and robotics

## Photos
> Add your build photos here

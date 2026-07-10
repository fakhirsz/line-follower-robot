/*
  Line Following Robot — Arduino
  Author: Muhammad Fakhir
  Description: An autonomous robot that follows a black line on a white surface
               using two IR sensors. Motor driver: L298N. Board: Arduino UNO.
*/

// IR Sensor pins
const int leftSensor  = 8;   // Left IR sensor digital output
const int rightSensor = 9;   // Right IR sensor digital output

// Motor A (Left motor) — L298N
const int motorA_IN1 = 2;
const int motorA_IN2 = 3;
const int motorA_EN  = 5;   // PWM

// Motor B (Right motor) — L298N
const int motorB_IN3 = 4;
const int motorB_IN4 = 7;
const int motorB_EN  = 6;   // PWM

// Speed settings
const int fullSpeed = 180;
const int turnSpeed = 120;

void setup() {
  pinMode(leftSensor,  INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(motorA_IN1, OUTPUT);
  pinMode(motorA_IN2, OUTPUT);
  pinMode(motorA_EN,  OUTPUT);
  pinMode(motorB_IN3, OUTPUT);
  pinMode(motorB_IN4, OUTPUT);
  pinMode(motorB_EN,  OUTPUT);

  Serial.begin(9600);
  Serial.println("Line Follower Ready.");
}

void loop() {
  int leftVal  = digitalRead(leftSensor);   // LOW = detects black line
  int rightVal = digitalRead(rightSensor);  // LOW = detects black line

  // Logic:
  // Both sensors on line    → move forward
  // Left on line only       → turn left
  // Right on line only      → turn right
  // Both off line           → stop

  if (leftVal == LOW && rightVal == LOW) {
    moveForward();
  }
  else if (leftVal == LOW && rightVal == HIGH) {
    turnLeft();
  }
  else if (leftVal == HIGH && rightVal == LOW) {
    turnRight();
  }
  else {
    stopMotors();
  }

  // Debug
  Serial.print("L: "); Serial.print(leftVal);
  Serial.print(" | R: "); Serial.println(rightVal);
}

void moveForward() {
  analogWrite(motorA_EN, fullSpeed);
  analogWrite(motorB_EN, fullSpeed);
  digitalWrite(motorA_IN1, HIGH);
  digitalWrite(motorA_IN2, LOW);
  digitalWrite(motorB_IN3, HIGH);
  digitalWrite(motorB_IN4, LOW);
}

void turnLeft() {
  analogWrite(motorA_EN, turnSpeed);
  analogWrite(motorB_EN, fullSpeed);
  digitalWrite(motorA_IN1, LOW);
  digitalWrite(motorA_IN2, HIGH);
  digitalWrite(motorB_IN3, HIGH);
  digitalWrite(motorB_IN4, LOW);
}

void turnRight() {
  analogWrite(motorA_EN, fullSpeed);
  analogWrite(motorB_EN, turnSpeed);
  digitalWrite(motorA_IN1, HIGH);
  digitalWrite(motorA_IN2, LOW);
  digitalWrite(motorB_IN3, LOW);
  digitalWrite(motorB_IN4, HIGH);
}

void stopMotors() {
  analogWrite(motorA_EN, 0);
  analogWrite(motorB_EN, 0);
  digitalWrite(motorA_IN1, LOW);
  digitalWrite(motorA_IN2, LOW);
  digitalWrite(motorB_IN3, LOW);
  digitalWrite(motorB_IN4, LOW);
}

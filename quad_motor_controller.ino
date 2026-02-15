/*
 * Quad Motor Controller
 * Description: Control 4 motors with variable speed adjustment
 * Motors connected to PWM pins: 3, 5, 6, 9
 * Each motor drives a circular disk (wheel)
 * All motors rotate clockwise simultaneously
 */

#define MOTOR_1_PIN 3
#define MOTOR_2_PIN 5
#define MOTOR_3_PIN 6
#define MOTOR_4_PIN 9

int motor1_speed = 150;
int motor2_speed = 150;
int motor3_speed = 150;
int motor4_speed = 150;

void setup() {
  Serial.begin(9600);
  
  pinMode(MOTOR_1_PIN, OUTPUT);
  pinMode(MOTOR_2_PIN, OUTPUT);
  pinMode(MOTOR_3_PIN, OUTPUT);
  pinMode(MOTOR_4_PIN, OUTPUT);
  
  Serial.println("=== Quad Motor Controller Initialized ===");
  Serial.println("All motors ready for operation");
  Serial.println("Speed range: 0 (OFF) to 255 (MAX)");
}

void loop() {
  runAllMotors();
  delay(100);
}

void setMotorSpeed(int pin, int speed) {
  speed = constrain(speed, 0, 255);
  analogWrite(pin, speed);
}

void setAllMotorSpeeds(int speed1, int speed2, int speed3, int speed4) {
  motor1_speed = constrain(speed1, 0, 255);
  motor2_speed = constrain(speed2, 0, 255);
  motor3_speed = constrain(speed3, 0, 255);
  motor4_speed = constrain(speed4, 0, 255);
  
  Serial.print("Motor speeds: M1:");
  Serial.print(motor1_speed);
  Serial.print(" M2:");
  Serial.print(motor2_speed);
  Serial.print(" M3:");
  Serial.print(motor3_speed);
  Serial.print(" M4:");
  Serial.println(motor4_speed);
}

void runAllMotors() {
  setMotorSpeed(MOTOR_1_PIN, motor1_speed);
  setMotorSpeed(MOTOR_2_PIN, motor2_speed);
  setMotorSpeed(MOTOR_3_PIN, motor3_speed);
  setMotorSpeed(MOTOR_4_PIN, motor4_speed);
}

void stopAllMotors() {
  setAllMotorSpeeds(0, 0, 0, 0);
  Serial.println("All motors stopped");
}

void increaseSpeed(int increment) {
  motor1_speed = constrain(motor1_speed + increment, 0, 255);
  motor2_speed = constrain(motor2_speed + increment, 0, 255);
  motor3_speed = constrain(motor3_speed + increment, 0, 255);
  motor4_speed = constrain(motor4_speed + increment, 0, 255);
  
  Serial.print("Speed increased to: ");
  Serial.println(motor1_speed);
  runAllMotors();
}

void decreaseSpeed(int decrement) {
  motor1_speed = constrain(motor1_speed - decrement, 0, 255);
  motor2_speed = constrain(motor2_speed - decrement, 0, 255);
  motor3_speed = constrain(motor3_speed - decrement, 0, 255);
  motor4_speed = constrain(motor4_speed - decrement, 0, 255);
  
  Serial.print("Speed decreased to: ");
  Serial.println(motor1_speed);
  runAllMotors();
}

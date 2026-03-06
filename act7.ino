#include <Servo.h>

// Create a Servo object to control the motor
Servo myServo;
// Define the pin the servo is connected to
const int servoPin = 9;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(0);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.length() > 0) {
      int angle = input.toInt();

      if (angle >= 0 && angle <= 180) {
        myServo.write(angle);
        Serial.print("Moved to ");
        Serial.print(angle);
        Serial.println(" degrees");
      } else {
        Serial.println("Invalid: Angle must be 0-180");
      }
    }
  }
}
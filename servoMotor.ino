#include <Servo.h>

Servo servoMotor;

void setup() {
  servoMotor.attach(3);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int degrees = Serial.parseInt();
    if (degrees >= 0 && degrees <= 180) {
      servoMotor.write(degrees);
      Serial.println("Moviendo el servomotor a " + String(degrees) + " grados.");
    } else {
      Serial.println("Los grados deben estar en el rango de 0 a 180.");
    }
  }
}


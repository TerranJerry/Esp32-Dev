#include <Arduino.h>

#define ledPin 2
int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(115200); // Default communication rate of the Bluetooth module
}
void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
 // Controlling the LED
 if (state == '1') {
  digitalWrite(ledPin, HIGH); // LED ON
  Serial.println("LED ON");
  delay(500);
  state = 0;
  digitalWrite(ledPin, LOW); // LED OFF
  }
  else{
    Serial.println("Waiting");
    delay(500);
  }
}
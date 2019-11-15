// Basic demo for accelerometer readings from Adafruit LIS3DH

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// I2C
Adafruit_LIS3DH accelerometer = Adafruit_LIS3DH();
#define CLICKTHRESHHOLD 80

long steps = 0;                   // step count. reset every card write
int minStepInterval = 50;         // min time between steps, in ms
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int x;
int y;
int z;

void setup(void) {
   Serial.begin(9600);   // initialize serial communication

  // 0x18 is the accelerometer's default I2C address:
  if (! accelerometer.begin(0x18)) {
    Serial.println("Couldn't start.");
    while (true);     // stop here and do nothing
  }

  // accelerometer range can be 2, 4, 8, or 16G:
  accelerometer.setRange(LIS3DH_RANGE_2_G);

  // 1 = single click only interrupt output
  accelerometer.setClick(1, CLICKTHRESHHOLD);
  pinMode(2, OUTPUT); //initialize thisPin as an output
  pinMode(3, OUTPUT); //initialize thisPin as an output
  pinMode(4, OUTPUT); //initialize thisPin as an output
  delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:
  accelerometer.read();
  x = accelerometer.x;
  y = accelerometer.y;
  z = accelerometer.z;
  Serial.println(y);

    if (x > 600) {
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);
  }
  if (y > 600) {
    digitalWrite(3, HIGH);
  }
  else {
    digitalWrite(3, LOW);
  }
  if (z > 600) {
    digitalWrite(4, HIGH);
  }
  else {
    digitalWrite(4, LOW);
  }
  //delay(500);

  //analogWrite(9, brightness);
  // read for clicks every 50 ms:
//  byte click = accelerometer.getClick();
//  if (click > 0) {
//    steps++;
//    digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
//    delay(500);                       // wait for a second
//    digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
//    delay(500);                       // wait for a second
//    Serial.println(steps);
//  }
//  delay(minStepInterval);
  
}

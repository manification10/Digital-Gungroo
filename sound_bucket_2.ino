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
  delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:
  accelerometer.read();
  x = accelerometer.x;
  y = accelerometer.y;
  z = accelerometer.z;

// Uncomment and test with different /n 
//  x = x/100;
//  y = y/100;
//  z = z/100;
   
  if (( 3 < x < 10 || -15 < x < -2) & (1 < y < 6 || -9 < y < -2) & (5 < z < 25 || -15 < z < -2))
  {Serial.println("1");}
  else if (( 7 < x < 30 || -30 < x < -7) & (2 < y < 15 || -20 < y < -4) & (14 < z < 40 || -25 < z < -9))
  {Serial.println("2");}
  else if (( 25 < x < 50 || -50 < x < -25) & (2 < y < 15 || -35 < y < -12) & (5 < z < 45 || -4 < z < -31))
  {Serial.println("3");}
  
  
  delay(minStepInterval);
  
}

// Basic demo for accelerometer readings from Adafruit LIS3DH

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// I2C
Adafruit_LIS3DH accelerometer = Adafruit_LIS3DH();
#define CLICKTHRESHHOLD1 50
#define CLICKTHRESHHOLD2 100
#define CLICKTHRESHHOLD3 150

#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3

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
  accelerometer.setClick(1, CLICKTHRESHHOLD1);
  accelerometer.setClick(2, CLICKTHRESHHOLD2);
  accelerometer.setClick(3, CLICKTHRESHHOLD3);

  
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  
  delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:
  accelerometer.read();
  x = accelerometer.x;
  y = accelerometer.y;
  z = accelerometer.z;

  //Serial.println(y);

// Uncomment and test with different /n 
//  x = x/1000;
//  Serial.println("X: "); Serial.println(x);
//  y = y/1000;
//  Serial.println("Y: "); Serial.println(y);
//  z = z/1000;
//  Serial.println("Z: "); Serial.println(z);
   
//  if (( 3 < x < 10 || -15 < x < -2) && (1 < y < 6 || -9 < y < -2) && (5 < z < 25 || -15 < z < -2))
//  {Serial.println("1");}
//  else if (( 7 < x < 30 || -30 < x < -7) && (2 < y < 15 || -20 < y < -4) && (14 < z < 40 || -25 < z < -9))
//  {Serial.println("2");}
//  else if (( 25 < x < 50 || -50 < x < -25) && (2 < y < 15 || -35 < y < -12) && (5 < z < 45 || -4 < z < -31))
//  {Serial.println("3");}

//  if (abs(y) > 3000)
//  {Serial.println("3");}
//  else if (abs(y) > 1000)
//  {Serial.println("2");}
//  else if (abs(y) > 600)
//  {Serial.println("1");}

  byte click = accelerometer.getClick();
  
  if (click > 5 ) {
      if (click > 80) 
      Serial.println("3");
      else if (click > 20)
      Serial.println("2");
      else
      Serial.println("1");
      delay(200); 
    }
    
  if (x > 600) {
    analogWrite(REDPIN, x);
  }
  else {
    analogWrite(REDPIN, 0);
  }
  if (y > 600) {
    analogWrite(GREENPIN, y);
  }
  else {
    analogWrite(GREENPIN, 0);
  }
  if (z > 600) {
    digitalWrite(BLUEPIN, z);
  }
  else {
    analogWrite(BLUEPIN, 0);
  }

//  Serial.println();
  
  //delay(minStepInterval);
  //delay(2000);
  
}

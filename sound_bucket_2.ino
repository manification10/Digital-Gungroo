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

long steps = 0;                   // step count. reset every card write
int minStepInterval = 50;         // min time between steps, in ms
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int x;
int y;
int z;
int n;
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

  
  // 1 = single click only interrupt output
  accelerometer.setClick(1, CLICKTHRESHHOLD1);
  accelerometer.setClick(2, CLICKTHRESHHOLD2);
  accelerometer.setClick(2, CLICKTHRESHHOLD3);
  delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:
//  accelerometer.read();
//  x = accelerometer.x;
//  y = accelerometer.y;
//  z = accelerometer.z;
//  
////  Serial.println("xyz values");
////  Serial.println(x);
////  Serial.println(y);
////  Serial.println(z);
// 
//  if (( -400 < x && x < 450) && ( -1600 < y && y < 2300) && (1500 < z && z < 17000))
//  {Serial.println("0");}
//  else if (( -500 < x && x < 1000) && ( -2400 < y && y < 4000) && (4000 < z && z < 20000))
//  {Serial.println("1");}
//  else if (( -3000 < x && x < 2000) && ( -3000 < y && y < 6000) && (5000 < z && z < 25000))
//  {Serial.println("2");}
//  else
//  {Serial.println("3");}
// 
////  delay(300);
  // read for clicks every 50 ms:
  byte click = accelerometer.getClick();
//  if (click > 0) {
//    steps++;
//    digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
//    delay(500);                       // wait for a second
//    digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
//    delay(500);                       // wait for a second
//    Serial.print("g");
//    Serial.println(click);
//  }
    if (click > 10 ) {
      if (click > 100) 
      Serial.println("3");
      else if (click > 30)
      Serial.println("2");
      else
      Serial.println("1");
      delay(200); 
    }
  //Serial.println(click);
  
  
}

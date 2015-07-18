
#include <Wire.h>
#include <ADXL345.h>

ADXL345 adxl;

void setup() {
  Serial.begin(9600);
  adxl.powerOn();
  
  adxl.setActivityX(1);
  adxl.setActivityY(1);
  adxl.setActivityZ(1);
}

void loop() {
  int timerEnd = millis() + 100;
  int x, y, z;
  adxl.readXYZ(&x, &y, &z); // needed to properly read values
  
  bool inverse[3] = {false};
  double ax, ay, az;
  
  while (1) {
    if (millis() > timerEnd) {
      adxl.readXYZ(&x, &y, &z);
      if (x > 30000) {
        inverse[0] = true;
        x = 65536 - x;
      }
      if (y > 30000) {
        inverse[1] = true;
        y = 65536 - y;
      }
      if (z > 30000) {
        inverse[2] = true;
        z = 65536 - z;
      }
      
      // 0 - no movement
      // 1 - up
      // 2 - down
      // 3 - left
      // 4 - right
      // 5 - top-left
      // 6 - top-right
      // 7 - bot-left
      // 8 - bot-right
      
      ax = x * 0.00390625;
      ay = y * 0.00390625;
      az = z * 0.00390625;
      break;
    }
  }
  
  int dir = 0;

  if (within(0, ax, 0.2) && ay >= 0.4 && az >= 0.5 && inverse[1]) {
    //Serial.println("downward");
    dir = 2;
  } else if (within(0, ax, 0.2) && ay >= 0.4 && az >= 0.75) {
    //Serial.println("upward");
    dir = 1;
  }
  
  if (ax >= 0.4 && within(0, ay, 0.1) && az >= 0.4 && inverse[0]) {
    //Serial.println("right");
    dir = 4;
  } else if (ax >= 0.4 && within(0, ay, 0.1) && az >= 0.4) {
    //Serial.println("left");
    dir = 3;
  }
  
  /*
  if (endG[0] >= 0.2 && endG[1] >= 0.2 && endG[2] >= 0.6) {
    //Serial.println("top-left");
  }
  */
  
  Serial.write(dir); // send direction over bluetooth
}

bool within(double num, double num2, double limit) {
  double error = abs(num2 - num);
  return (error <= limit);
}

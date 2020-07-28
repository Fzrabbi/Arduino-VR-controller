#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

int w = 9;  // Set a button to any pin
int s = 10;
int a = 11;
int d = 12;
int mouse_left = 13;

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;

void setup() {
  pinMode(w, INPUT);  // Set the button as an input
  digitalWrite(w, HIGH);  // Pull the button high

    pinMode(a, INPUT);  // Set the button as an input
  digitalWrite(a, HIGH);  // Pull the button high

    pinMode(s, INPUT);  // Set the button as an input
  digitalWrite(s, HIGH);  // Pull the button high

    pinMode(d, INPUT);  // Set the button as an input
  digitalWrite(d, HIGH);  // Pull the button high

  pinMode(mouse_left, INPUT);  // Set the button as an input
  digitalWrite(mouse_left, HIGH);  // Pull the button high
  
  Serial.begin(38400);
  

  //Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
    }
    //delay(10000);
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  vx = (gx+300)/200;  
  vy = -(gz+100)/200; 
  
  //Mouse.move(vx, vy);
  Serial.write(vx);
  Serial.write(vy);
  //Serial.println(vx);
  //Serial.println(vy);
  delay(20);
  
  //if (digitalRead(w) == 0||digitalRead(s) == 0||digitalRead(a) == 0||digitalRead(d) == 0)  // if the button goes low
  //{
    if (digitalRead(w) == 0)  // if the button goes low
    {
      Serial.write('1');  // send a 'z' to the computer via Keyboard HID
    }
    else if (digitalRead(s) == 0)  // if the button goes low
    {
      Serial.write('2');  // send a 'z' to the computer via Keyboard HID
    }
    else if (digitalRead(a) == 0)  // if the button goes low
    {
      Serial.write('3');  // send a 'z' to the computer via Keyboard HID
    }
    else if (digitalRead(d) == 0)  // if the button goes low
    {
      Serial.write('4');  // send a 'z' to the computer via Keyboard HID
    }
    else if (digitalRead(mouse_left) == 0)  // if the button goes low
    {
      Serial.write('5');  // send a 'z' to the computer via Keyboard HID
    }
  //}
    else{
      Serial.write('0');
    }
  
}

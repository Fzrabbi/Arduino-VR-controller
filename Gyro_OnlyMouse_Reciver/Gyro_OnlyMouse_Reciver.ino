

#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Mouse.h>
#include <Keyboard.h>

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx,vy;
int w=0;
int a=0;
int s=0;
int d=0;
int mouse_left=0;

int button=0;
int garbage=0;
void setup() {
  Serial1.begin(38400);
  Mouse.begin();
  //Wire.begin();
  //mpu.initialize();
  //if (!mpu.testConnection()) {
   // while (1);
   // }
   while(1){
      if(Serial1.available()>0){
        garbage=Serial1.read();
        if(garbage=='0'){
          break;
        }
      }
   }
}

void loop() {
  //mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  //vx = (gx+300)/200;  
  //vy = -(gz+100)/200; 
  if(Serial1.available()>2){
    vx=Serial1.read();
    vy=Serial1.read();
    button=Serial1.read();
    Mouse.move(vx, vy);
    
    
    Serial.println(vx);
    Serial.println(vy);
    Serial.println(button);

     
    if (button == '1')  // if the button goes low
    {
      Keyboard.write('w');
      Keyboard.write('w');
      Keyboard.write('w');
      Keyboard.write('w');
      Keyboard.write('w');
      Keyboard.write('w');
      Keyboard.write('w');
      Keyboard.write('w'); 
      button=0;// send a 'z' to the computer via Keyboard HID
      //delay(100);  // delay so there aren't a kajillion z's
    }
    if (button == '2')  // if the button goes low
    {
      Keyboard.write('s');
      Keyboard.write('s');
      Keyboard.write('s');
      Keyboard.write('s');
      Keyboard.write('s');
      Keyboard.write('s');
      Keyboard.write('s');
      Keyboard.write('s'); 
      button=0;// send a 'z' to the computer via Keyboard HID
      //delay(100);  // delay so there aren't a kajillion z's
    }
    if (button == '3')  // if the button goes low
    {
      Keyboard.write('a');
      Keyboard.write('a');
      Keyboard.write('a');
      Keyboard.write('a');
      Keyboard.write('a');
      Keyboard.write('a');
      Keyboard.write('a');
      Keyboard.write('a'); 
      button=0;// send a 'z' to the computer via Keyboard HID
      //delay(100);  // delay so there aren't a kajillion z's
    }
    if (button == '4')  // if the button goes low
    {
      Keyboard.write('d');
      Keyboard.write('d');
      Keyboard.write('d');
      Keyboard.write('d');
      Keyboard.write('d');
      Keyboard.write('d');
      Keyboard.write('d');
      Keyboard.write('d'); 
      button=0;// send a 'z' to the computer via Keyboard HID
      //delay(100);  // delay so there aren't a kajillion z's
    }
    if (button == '5')  // if the button goes low
    {
      Mouse.click(); 
      button=0;// send a 'z' to the computer via Keyboard HID
      //delay(100);  // delay so there aren't a kajillion z's
    }
    if (button == '6')  // if the button goes low
    {
      Mouse.click(MOUSE_RIGHT); 
      button=0;// send a 'z' to the computer via Keyboard HID
      //delay(100);  // delay so there aren't a kajillion z's
    }
 
  
  //delay(20);
  }
}

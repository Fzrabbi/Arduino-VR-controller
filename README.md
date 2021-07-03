# Arduino-VR-controller
 
1/Watch the Demonstration VIDEO
2/READ the documentation file 
All arduino codes are in the directory.
Components:
1. Two Bluetooth Module Breakout (HC-05): The HC-05 has two operating modes, one is the Data mode in which it can send and receive data from other Bluetooth devices and the other is the AT Command mode where the default device settings can be changed. We can operate the device in either of these two modes by using the key pin as explained in the pin description.
It is very easy to pair the HC-05 module with microcontrollers because it operates using the Serial Port Protocol (SPP). Simply power the module with +5V and connect the Rx pin of the module to the Tx of MCU and Tx pin of module to Rx of MCU as shown in the figure below
 
2. gy-521 (6 DOF Accelerometer Gyroscope  MPU 5060): The InvenSense MPU-6050 sensor contains a MEMS accelerometer and a MEMS gyro in a single chip. It is very accurate, as it contains 16-bits analog to digital conversion hardware for each channel. Therefor it captures the x, y, and z channel at the same time. The sensor uses the I2C-bus to interface with the Arduino.
The MPU-6050 is not expensive, especially given the fact that it combines both an accelerometer and a gyro.
 

3. 4 Control Buttons: 
 
4. Array Buttons:
 
5. Push buttons:
 
6. Battery/Powerbank:
 
7. Arduino Uno REV3:
  
8. Arduino Pro micro:
 

9. VR cardboad / box:
 
Softwares:
1.	Arduino Ide.
2.	TrinusVR Detop Application.
3.	TrinusVR Android app.

Working Procedure:
1.	We will use arduino pro micro as our keyboard/mouse.
2.	And the Uno REV3 for sending serial bits through Bluetooth module pair to make our controller working wirelessly.
3.	A pair of Bluetooth will set as master and slave.
4.	One Bluetooth will be connected with arduino UNO and the other will be connected with Pro micro.
5.	The Uno will be set on the controller and using the MASTER HC-5, the buttons it will send different serial value to the slave HC-05(which is connected with the pro micro) for pressing keyboard keys.
6.	The pro micro will be connected with the USB port of the PC to act like a USB keyboard/mouse/controller.
7.	SDA & SCL pin of gy-521 will connected with the controller UNO analog pin A4 & A5.
8.	With the help of gy-521 we will be controlling the mouse.
9.	Battery/Powerbank will be sued for power up the uno which runs wirelessly.
10.	Finally we will use the TrinusVR software to share the Display with VR Box.



Arduino Codes:

  Master device(The Controller):
1.	Initializing The libraries & declaring the pins for keyboard and mouse.
 


2.	Setup the Input_pullup.
 







3.	Loop section:
1.	Getting the GYRO value gx & gy and write(send) to the slave pro micro.
 




2.	Sending the button press to Pro micro which will work as keyboard HID 


 

Slave device(Pro micro):
1.	Initializing The libraries & declaring the pins for keyboard and mouse
 

2.	Slave Setup & sync the data captured from MASTER
 
3.	Capture the Data continuously from MASTER
 


Circuit Diagram:
 
Final Project:

 

END

                       //MASTER??\\

int w = 9;  // Set a button to any pin
int s = 10;
int a = 11;
int d = 12;

/*int w_state = 0;  
int s_state = 0;
int a_state = 0;
int d_state = 0;*/
void setup() {
  pinMode(w, INPUT);  // Set the button as an input
  digitalWrite(w, HIGH);  // Pull the button high

    pinMode(a, INPUT);  // Set the button as an input
  digitalWrite(a, HIGH);  // Pull the button high

    pinMode(s, INPUT);  // Set the button as an input
  digitalWrite(s, HIGH);  // Pull the button high

    pinMode(d, INPUT);  // Set the button as an input
  digitalWrite(d, HIGH);  // Pull the button high
  Serial.begin(38400);
}

void loop() {
  if (digitalRead(w) == 0)  // if the button goes low
  {
    Serial.write('1');  // send a 'z' to the computer via Keyboard HID
    //delay(100);  // delay so there aren't a kajillion z's
  }

  /*  if (digitalRead(a) == 0)  // if the button goes low
  {
    Keyboard.write('a');  // send a 'z' to the computer via Keyboard HID
    //delay(100);  // delay so there aren't a kajillion z's
  }
    if (digitalRead(s) == 0)  // if the button goes low
  {
    Keyboard.write('s');  // send a 'z' to the computer via Keyboard HID
    //delay(100);  // delay so there aren't a kajillion z's
  }

    if (digitalRead(d) == 0)  // if the button goes low
  {
    Keyboard.write('d');  // send a 'z' to the computer via Keyboard HID
    //delay(100);  // delay so there aren't a kajillion z's
  }*/
}

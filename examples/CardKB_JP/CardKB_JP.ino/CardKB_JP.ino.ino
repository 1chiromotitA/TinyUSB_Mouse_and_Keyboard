//Include this module whether using Arduino stack or TinyUSB stack
#include <TinyUSB_Mouse_and_KeyboardJP.h>
#define CARDKB_ADDR 0x5F
#include <Wire.h>

void setup() {
  Keyboard.begin(); //Unlike Arduino Keyboard.h and Mouse.h, 
  Mouse.begin();    //    you must use "begin" method for both mouse and keyboard.
  Wire.begin();
};

void loop() {
  delay(2);
  //Serial.println("wait");
  static bool keyPressedPreviously = false;
  bool anyKeyPressed = false;
  
  Wire.requestFrom(CARDKB_ADDR, 1); 
  while (Wire.available()) 
  {
    char c = Wire.read();
    if (c != 0)
    {
      Serial.println(c, HEX);
      Keyboard.write(c);
    }
  }
}


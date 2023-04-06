#include <Arduino.h>
#include "Keyboard.h"

#define COLS 3
#define ROWS 2

const uint8_t PIN_BTN_ROW[ROWS] = {15,5}; // SETUP ROW-OUTPUTS
const uint8_t PIN_BTN_COL[COLS] = {2,3,4}; // SETUP COLUMN-INPUTS

uint32_t unpressDelay = 100; // Holding button for this time (milliseconds)

struct MyBtn
{
  bool pressed = false;
  bool pressedOld = false;
  uint32_t pressTime = 0;

  uint8_t row = 0;
  uint8_t col = 0;

  uint8_t mod = 0;
  uint8_t mod2 = 0;
  uint8_t key = 0;

  void pressHotKey() {
    if (mod != 0)
      Keyboard.press(mod);
    delay(10);
    if (mod2 != 0)
      Keyboard.press(mod2);
    delay(10);
    if (key != 0)
      Keyboard.press(key);
    delay(10);
  }

  void releaseHotKey() {
    if (mod != 0)
      Keyboard.release(mod);
    delay(10);
    if (mod2 != 0)
      Keyboard.release(mod2);
    delay(10);
    if (key != 0)
      Keyboard.release(key); 
    delay(10);   
  }
  void change(bool val) {
    if (val && !pressedOld){
      pressed = true;
      pressTime = millis();
      pressHotKey();
      pressedOld = pressed;
    } 
    else if (!val && pressedOld) {
      if (millis() > pressTime + unpressDelay) {
        pressed = false;
        releaseHotKey();
        pressedOld = pressed;
      }
    }
  }
};
MyBtn btns[ROWS][COLS];

void readBtns() {
  for (uint8_t r = 0; r < ROWS; r++) {
    digitalWrite(PIN_BTN_ROW[r], 1);
    for (uint8_t c = 0; c < COLS; c++) {
      btns[r][c].change(digitalRead(PIN_BTN_COL[c]));
    }
    digitalWrite(PIN_BTN_ROW[r], 0);
  }
}

void debugBtns() {
  Serial.println();
  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Serial.print(btns[r][c].pressed);
    }
    Serial.println();
  }
}

void setup() {
  Serial.begin(115200);

  for (uint8_t r = 0; r < ROWS; r++) {
    pinMode(PIN_BTN_ROW[r], OUTPUT);
    digitalWrite(PIN_BTN_ROW[r], 0);
  }
  for (uint8_t c = 0; c < COLS; c++) {
    pinMode(PIN_BTN_COL[c], INPUT);
  }
  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      btns[r][c].row = r;
      btns[r][c].col = c;
    }
  }

// BUTTONS:
  btns[0][0].mod = KEY_LEFT_CTRL;
  btns[0][0].mod2 = KEY_LEFT_SHIFT;
  btns[0][0].key = '1';
  btns[0][1].mod = KEY_LEFT_CTRL;
  btns[0][1].mod2 = KEY_LEFT_SHIFT;
  btns[0][1].key = '2';
  btns[0][2].mod = KEY_LEFT_CTRL;
  btns[0][2].mod2 = KEY_LEFT_SHIFT;
  btns[0][2].key = '3';
  btns[1][0].mod = KEY_LEFT_CTRL;
  btns[1][0].mod2 = KEY_LEFT_SHIFT;
  btns[1][0].key = '4';
  btns[1][1].mod = KEY_LEFT_CTRL;
  btns[1][1].mod2 = KEY_LEFT_SHIFT;
  btns[1][1].key = '5';
  btns[1][2].mod = KEY_LEFT_CTRL;
  btns[1][2].mod2 = KEY_LEFT_SHIFT;
  btns[1][2].key = '6';
}

void loop() {
  readBtns();
  debugBtns();
}
/*
  Sidney McAdams
  GyroSNAKE
*/

//DISPLAY
#include <SFE_MicroOLED.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display1(OLED_RESET);
Adafruit_SSD1306 display2(OLED_RESET);

//MPU-6050
const int MPU_addr = 0x68; // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
int snakeX = 64;
int snakeY = 32;
int snakeDir = 0;

// FOR CHANGING SCREEN CASES
int mode = 0;
//int modes = 3;
int lastMode = -1;
int curSelection = 0;
int button1 = 1;
int buttonDelay = 100;
boolean debug = true;
boolean activeScreen = 1;

// CHECK BUTTON STATE
int checkButton() {
  if (digitalRead(button1) == HIGH) {
    delay(buttonDelay);
    if (debug) {
      Serial.println("LOW");
    } return 1;
  }
  return 0;
}

void setup() {
  initDisplay();
  initAccel();
  initBUTTON();
}

void initDisplay()   {
  Serial.begin(9600);
  display1.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display1.clearDisplay(); // clears screen

  display2.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display2.clearDisplay();
}

void initAccel() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
}

void initBUTTON() {
  pinMode(button1, INPUT);
}


void loop() {
  loadMode();
}

void loadMode() {
  switch (mode) {
    case 0: splash(); break;
    case 1: mainMenu(); break;
    case 2: originalSnake(); break;
    case 3: advanceSnake(); break;
    case 4: help(); break;
    case 5: about(); break;
  }
  // Clear Screen if Mode Changes
  if (lastMode != mode) {
    lastMode = mode;
    display1.clearDisplay();
    display2.clearDisplay();
  }
}







//SCORE
void originalSnakeScore() {
  display1.setCursor(0, 0);
  display1.setTextColor(WHITE, BLACK);
  display1.setTextWrap(true);
  display1.setTextSize(1);
  display1.println("0070");

  display1.display();

  display2.setCursor(0, 0);
  display2.setTextColor(WHITE, BLACK);
  display2.setTextWrap(true);
  display2.setTextSize(1);
  display2.println("0070");

  display2.display();
}

void drawSnake1() {
  display1.drawPixel(snakeX, snakeY, WHITE);
  display1.display();
}

void drawSnake2() {
  display2.drawPixel(snakeX, snakeY, WHITE);
  display2.display();
}

void moveSnake() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true); // request a total of 14 registers
  AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  //AcZ = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  // Snake Dir - 0 Up 1 Down 2 Left 3 Right
  Serial.println(AcX);
  if (AcX < -10000) {
    snakeDir = 2;
  }
  if (AcX > 10000) {
    snakeDir = 3;
  }
  if (AcY < -10000) {
    snakeDir = 1;
  }
  if (AcY > 10000) {
    snakeDir = 0;
  }

  //Serial.println(snakeDir);

  if (snakeDir == 2) {
    snakeX = max(snakeX - 1, 0);
  }
  if (snakeDir == 3) {
    snakeX = min(snakeX + 1, 127);
  }
  if (snakeDir == 1) {
    snakeY = max(snakeY - 1, 0);
  }
  if (snakeDir == 0) {
    snakeY = min(snakeY + 1, 63);
  }
}

void livescreen(){
  if(display1.display()){
    activeScreen = true;
  }
}

void originalSnake() {
  moveSnake();
  drawSnake1();
  drawSnake2();
  originalSnakeScore();
  int b = checkButton();
  if ( b == 1) {
    mode = 0;
  }
}




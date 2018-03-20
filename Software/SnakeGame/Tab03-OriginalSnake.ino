//SCORE
void originalSnakeScore() {
  if (activeScreen == 0) {
    display1.setCursor(0, 0);
    display1.setTextColor(WHITE, BLACK);
    display1.setTextWrap(true);
    display1.setTextSize(1);
    display1.println(String(score, DEC));
  } else if (activeScreen == 1) {
    display2.setCursor(0, 0);
    display2.setTextColor(WHITE, BLACK);
    display2.setTextWrap(true);
    display2.setTextSize(1);
    display2.println(String(score, DEC));
  }
}

//DRAW SNAKE1 ON SCREEN1
void drawSnake1() {
  for (int i = 0; i < snakeLength; i++) {
    display1.drawPixel(snakeX[i], snakeY[i], WHITE);
  }
  display1.drawPixel(snakeX[snakeLength], snakeY[snakeLength], BLACK); //erase where the snake has been
}

//DRAW SNAKE2 ON SCREEN2
void drawSnake2() {
  for (int i = 0; i < snakeLength; i++) {
    display2.drawPixel(snakeX[i], snakeY[i], WHITE);
  }
  display2.drawPixel(snakeX[snakeLength], snakeY[snakeLength], BLACK);
}

void spawnFood() {
  foodX = random(10, 122);
  foodY = random(10, 59);
}


//MAKES THE SNAKE MOVE WITH MOTION OF ACCELEROMETER
void moveSnake() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true); // request a total of 14 registers
  AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  // Snake Dir - 0 Up 1 Down 2 Left 3 Right
  Serial.println("AcZ = "); Serial.println(AcZ);
  if (AcX < -10000) {
    snakeDir = 1;
  }
  else if (AcX > 10000) {
    snakeDir = 0;
  }
  else if (AcY < -10000) {
    snakeDir = 2;
  }
  else if (AcY > 10000) {
    snakeDir = 3;
  }

  //Serial.println(snakeDir);
  int newX = snakeX[0];
  int newY = snakeY[0];

  if (snakeDir == 2) {
    newX = max(newX - 1, 0);
  }
  if (snakeDir == 3) {
    newX = min(newX + 1, 127);
  }
  if (snakeDir == 1) {
    newY = max(newY - 1, 0);
  }
  if (snakeDir == 0) {
    newY = min(newY + 1, 63);
  }

  // FOR WHEN THE SNAKE GOES UP
  for (int i = 8; i >= 0; i--) {
    snakeX[i + 1] = snakeX[i];
    snakeY[i + 1] = snakeY[i];
  }
  snakeX[0] = newX;
  snakeY[0] = newY;
}

void collectFood() {
  display1.drawPixel(foodX, foodY, WHITE);
  display2.drawPixel(foodX, foodY, WHITE);

  if (snakeX[0] == foodX && snakeY[0] == foodY) {
    score += 10;

    tone(8, 1000, 10);
    tone(8, 1020, 10);
    tone(8, 1040, 10);
    tone(8, 1000, 10);
    tone(8, 1000, 10);

    snakeLength = min(snakeLength + 1, 9);

    spawnFood();
  }
}

/*
  void livescreen(){
  if(display1.display()){
    activeScreen = true;
  }
  }
*/

void originalSnake() {
  moveSnake();
  collectFood();
  drawSnake1();
  drawSnake2();
  originalSnakeScore();

  int b = checkButton();
  if ( b == 1) {
    mode = 0;
    score = 0;
    snakeX[0] = 64;
    snakeY[0] = 32;
    snakeLength = 1;
  }

  //display1.display();
  //display2.display();
}




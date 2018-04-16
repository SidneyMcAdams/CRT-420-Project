// DISPLAYS THE SCORE
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

// DRAWS SNAKE1 ON SCREEN1
void drawSnake1() {
  for (int i = 0; i < snakeLength; i++) {
    display1.drawPixel(snakeX[i], snakeY[i], WHITE);
  }
  display1.drawPixel(snakeX[snakeLength], snakeY[snakeLength], BLACK); //erase where the snake has been
}

// DRAWS SNAKE2 ON SCREEN2
void drawSnake2() {
  for (int i = 0; i < snakeLength; i++) {
    display2.drawPixel(snakeX[i], snakeY[i], WHITE);
  }
  display2.drawPixel(snakeX[snakeLength], snakeY[snakeLength], BLACK);
}

// SETS THE LOCATION OF THE FOOD AT "RANDOM" COORDINATES
void spawnFood() {
  foodX = random(10, 122);
  foodY = random(10, 59);
  foodScreen = random(0, 2);
}


// MAKES THE SNAKE MOVE WITH MOTION OF ACCELEROMETER
void moveSnake() {
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

  // Serial.println(snakeDir);
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

// DRAWS FOOD AND COLLECTS FOOD
void collectFood() {
  if(foodScreen == 0 && activeScreen == 0){
      display1.drawPixel(foodX, foodY, WHITE);
      if(mode == 3){display1.fillRect(foodX, foodY, 2, 2, WHITE);}
  }
  if(foodScreen == 1 && activeScreen == 1){
    display2.drawPixel(foodX, foodY, WHITE);
    if(mode == 3){display2.fillRect(foodX, foodY, 2, 2, WHITE);}
  }

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

// BRINGS ALL THE FUNCTIONS TO SETUP TO WORK AND DISPLAY ON THE SCREENS
void originalSnake() {
  moveSnake();
  collectFood();

  if(activeScreen == 1){drawSnake1();}
  else{drawSnake2();}
  
  originalSnakeScore();

  int b = checkButton();
  if ( b == 1) {
    mode = 0;
    score = 0;
    snakeX[0] = 64;
    snakeY[0] = 32;
    snakeLength = 1;
  }
}




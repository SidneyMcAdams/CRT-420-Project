// DISPLAYS SNAKES SCORE AND LIVES ON THE SCREEN
void advanceSnakeScore() {
  if (activeScreen == 0) {
    //SCORE1
    display1.setCursor(0, 0);
    display1.setTextColor(WHITE, BLACK);
    display1.setTextWrap(true);
    display1.setTextSize(1);
    display1.println(String(score, DEC));

    //LIVES1
    display1.setCursor(122, 0);
    display1.setTextColor(WHITE, BLACK);
    display1.setTextWrap(true);
    display1.setTextSize(1);
    display1.println("3");
  } else {
    //SCORE2
    display2.setCursor(0, 0);
    display2.setTextColor(WHITE, BLACK);
    display2.setTextWrap(true);
    display2.setTextSize(1);
    display2.println(String(score, DEC));

    //LIVES2
    display2.setCursor(122, 0);
    display2.setTextColor(WHITE, BLACK);
    display2.setTextWrap(true);
    display2.setTextSize(1);
    display2.println("3");
  }
}

// DRAWS PIXEL SNOW ON SCREEN
void drawNotFood() {
  if (millis() - nftimer > 1000) {
    display1.drawPixel(random(128), random(64), WHITE);
    display2.drawPixel(random(128), random(64), WHITE);
    nftimer = millis();
  }
}

// BRINGS ALL THE FUNCTIONS TO SETUP TO WORK AND DISPLAY ON THE SCREENS
void advanceSnake() {
  collectFood();
  moveSnake();
  if (activeScreen == 0) {
    drawSnake1();
  } else {
    drawSnake2();
  }
  advanceSnakeScore();
  drawNotFood();

  int b = checkButton();
  if ( b == 1) {
    mode = 0;
    score = 0;
    snakeX[0] = 64;
    snakeY[0] = 32;
  }
}






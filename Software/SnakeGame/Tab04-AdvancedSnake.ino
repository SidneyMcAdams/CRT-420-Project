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



void drawNotFood() {
  if (millis() - nftimer > 1000) {
    display1.drawPixel(random(128), random(64), WHITE);
    display2.drawPixel(random(128), random(64), WHITE);
    nftimer = millis();
  }

  /*
  if (activeScreen == 0) {
    for ( int i = 0; i < 20; i++) {
      display1.drawPixel(nfX[i], nfY[i], WHITE);
    }
  } else {
    for ( int i = 0; i < 20; i++) {
      display2.drawPixel(nfX[i], nfY[i], WHITE);
    }
  }
  */
}

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






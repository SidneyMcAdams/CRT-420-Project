void advanceSnakeScore() {
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

void walls() {
  //WALLS1
  for (int i = 30; i < 50; i++) {
    display1.drawPixel(10, i, WHITE);
  }
  //WALLS2
  for (int i = 20; i < 40; i++) {
    display2.drawPixel(20, i, WHITE);
  }
}

void advanceSnake() {
  collectFood();
  moveSnake();
  drawSnake1();
  drawSnake2();
  advanceSnakeScore();
  walls();

  int b = checkButton();
  if ( b == 1) {
    mode = 0;
    score = 0;
    snakeX[0] = 64;
    snakeY[0] = 32;
  }

  //display1.display();
  //display2.display();
}






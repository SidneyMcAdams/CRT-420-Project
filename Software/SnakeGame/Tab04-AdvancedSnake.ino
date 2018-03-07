void advanceSnakeScore() {
  //SCORE1
  display1.setCursor(0, 0);
  display1.setTextColor(WHITE, BLACK);
  display1.setTextWrap(true);
  display1.setTextSize(1);
  display1.println("0000");

  //LIVES1
  display1.setCursor(122, 0);
  display1.setTextColor(WHITE, BLACK);
  display1.setTextWrap(true);
  display1.setTextSize(1);
  display1.println("3");

  display1.display();

  //SCORE2
  display2.setCursor(0, 0);
  display2.setTextColor(WHITE, BLACK);
  display2.setTextWrap(true);
  display2.setTextSize(1);
  display2.println("0000");

  //LIVES2
  display2.setCursor(122, 0);
  display2.setTextColor(WHITE, BLACK);
  display2.setTextWrap(true);
  display2.setTextSize(1);
  display2.println("3");

  display2.display();
}

void walls() {
  //WALLS1
  for (int i = 30; i < 50; i++) {
    display1.drawPixel(10, i, WHITE);
  }

  display1.display();

  //WALLS2
  for (int i = 20; i < 40; i++) {
    display2.drawPixel(20, i, WHITE);
  }
  display2.display();
}

void advanceSnake() {
  moveSnake();
  drawSnake1();
  drawSnake2();
  advanceSnakeScore();
  walls();
  int b = checkButton();
  if ( b == 1) {
    mode = 0;
  }
}






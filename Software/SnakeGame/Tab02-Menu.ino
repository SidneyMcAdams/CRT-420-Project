// APPLIES THE CASE MODES IN TEXT IN A ORGANIZED FASHION ON THE SCREEN  
void mainMenu() {

  //Button Input & Accel. Input
  int b = checkButton();
  if ( b == 1) {
    mode = curSelection + 2;
  }// UP
  if (AcX > 10000) {
    curSelection = (curSelection + 1) % 4;
  }// DOWN
  if (AcX < -10000) {
    curSelection--;
    if (curSelection < 0) {
      curSelection = 3;
    }
  }

  if (activeScreen == 0) {

    // MENU
    display1.setCursor(0, 0);
    display1.setTextColor(WHITE, BLACK);
    display1.setTextSize(2);
    display1.setTextWrap(true);
    display1.println("MENU");

    //ORIGINAL SNAKE
    display1.setCursor(0, 20);
    display1.setTextSize(1);
    if (curSelection == 0) {
      display1.fillRect(0, 19, 127, 10, WHITE);
      display1.setTextColor(BLACK);
    }
    else {
      display1.fillRect(0, 19, 128, 10, BLACK);
      display1.setTextColor(WHITE);
    }
    display1.println("+ ORIGINAL SNAKE");

    //ADVANCED SNAKE
    display1.setCursor(0, 30);
    display1.setTextSize(1);
    if (curSelection == 1) {
      display1.fillRect(0, 29, 127, 10, WHITE);
      display1.setTextColor(BLACK);
    }
    else {
      display1.fillRect(0, 29, 128, 10, BLACK);
      display1.setTextColor(WHITE);
    }
    display1.println("+ ADVANCED SNAKE");

    //HELP
    display1.setCursor(0, 40);
    display1.setTextSize(1);
    if (curSelection == 2) {
      display1.fillRect(0, 39, 127, 10, WHITE);
      display1.setTextColor(BLACK);
    }
    else {
      display1.fillRect(0, 39, 128, 10, BLACK);
      display1.setTextColor(WHITE);
    }
    display1.println("+ HELP");

    //ABOUT
    display1.setCursor(0, 50);
    display1.setTextSize(1);
    if (curSelection == 3) {
      display1.fillRect(0, 49, 127, 10, WHITE);
      display1.setTextColor(BLACK);
    }
    else {
      display1.fillRect(0, 49, 128, 10, BLACK);
      display1.setTextColor(WHITE);
    }
    display1.println("+ ABOUT");
    
  } else {

    /**********************************************************************************************
    ***********************************************************************************************/

    //MENU
    display2.setCursor(0, 0);
    display2.setTextColor(WHITE, BLACK);
    display2.setTextSize(2);
    display2.setTextWrap(true);
    display2.println("MENU");

    //ORIGINAL SNAKE
    display2.setCursor(0, 20);
    display2.setTextSize(1);
    if (curSelection == 0) {
      display2.fillRect(0, 19, 127, 10, WHITE);
      display2.setTextColor(BLACK);
    }
    else {
      display2.fillRect(0, 19, 128, 10, BLACK);
      display2.setTextColor(WHITE);
    }
    display2.println("+ ORIGINAL SNAKE");

    //ADVANCED SNAKE
    display2.setCursor(0, 30);
    display2.setTextSize(1);
    if (curSelection == 1) {
      display2.fillRect(0, 29, 127, 10, WHITE);
      display2.setTextColor(BLACK);
    }
    else {
      display2.fillRect(0, 29, 128, 10, BLACK);
      display2.setTextColor(WHITE);
    }
    display2.println("+ ADVANCED SNAKE");

    //HELP
    display2.setCursor(0, 40);
    display2.setTextSize(1);
    if (curSelection == 2) {
      display2.fillRect(0, 39, 127, 10, WHITE);
      display2.setTextColor(BLACK);
    }
    else {
      display2.fillRect(0, 39, 128, 10, BLACK);
      display2.setTextColor(WHITE);
    }
    display2.println("+ HELP");

    //ABOUT
    display2.setCursor(0, 50);
    display2.setTextSize(1);
    if (curSelection == 3) {
      display2.fillRect(0, 49, 127, 10, WHITE);
      display2.setTextColor(BLACK);
    }
    else {
      display2.fillRect(0, 49, 128, 10, BLACK);
      display2.setTextColor(WHITE);
    }
    display2.println("+ ABOUT");
  }
  //display2.display();
}


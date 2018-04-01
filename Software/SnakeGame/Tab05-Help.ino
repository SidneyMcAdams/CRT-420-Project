void help() {
  //Line 1
  if (activeScreen == 0) {
  display1.setCursor(12, 5);
  display1.setTextSize(1);
  display1.println("ROTATE FORWARD OR");

  display1.setCursor(15, 15);
  display1.setTextSize(1);
  display1.println("BACKWARD TO MOVE");

  display1.setCursor(27, 25);
  display1.setTextSize(1);
  display1.println("THROUGH MENU");

  //Line 2
  display1.setCursor(5, 35);
  display1.setTextSize(1);
  display1.println("USE BUTTON TO SELECT");

  display1.setCursor(17, 45);
  display1.setTextSize(1);
  display1.println("GAME AND GO BACK");

  //Line 3
  display1.setCursor(5, 55);
  display1.setTextSize(1);
  display1.println("ROTATE TO MOVE SNAKE");

  //display1.display();
  }else{
  //Line 1
  display2.setCursor(12, 5);
  display2.setTextSize(1);
  display2.println("ROTATE FORWARD OR");

  display2.setCursor(15, 15);
  display2.setTextSize(1);
  display2.println("BACKWARD TO MOVE");

  display2.setCursor(27, 25);
  display2.setTextSize(1);
  display2.println("THROUGH MENU");

  //Line 2
  display2.setCursor(5, 35);
  display2.setTextSize(1);
  display2.println("USE BUTTON TO SELECT");

  display2.setCursor(17, 45);
  display2.setTextSize(1);
  display2.println("GAME AND GO BACK");

  //Line 3
  display2.setCursor(5, 55);
  display2.setTextSize(1);
  display2.println("ROTATE TO MOVE SNAKE");

  //display2.display();
  }
 int b = checkButton();
  if ( b == 1) {
    mode = 0;
  }
}


#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Encoders encoders;
Zumo32U4Buzzer buzzer;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4LCD display;

const char encoderErrorLeft[] PROGMEM = "!<c2";
const char encoderErrorRight[] PROGMEM = "!<e2";

const int FULL_360 = 5130;

char report[80];

void setup() {
  // put your setup code here, to run once:

}

void reset()
{
  motors.setSpeeds(0, 0);
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();
  delay(200);
}

void goForward(int16_t amount)
{

  int16_t left = encoders.getCountsLeft();
  while(left < amount)
      {
        motors.setSpeeds(75, 75);
        left = encoders.getCountsLeft();

        display.clear();
        display.print(left);

        
      }

      reset();
}

void goBackward(int16_t amount)
{
  int16_t left = encoders.getCountsLeft();
  while(left > -amount)
      {
        motors.setSpeeds(-75, -75);
        left = encoders.getCountsLeft();

        display.clear();
        display.print(left);

        
      }

      reset();
}

void turnRight(int degrees)
{

  int16_t left = encoders.getCountsLeft();
  
  while(left < (FULL_360 * ( degrees / 360.0)))
      {
        motors.setSpeeds(75, 0);
        left = encoders.getCountsLeft();

        display.clear();
        display.print(left);

        
      }

      reset();
      
}

void turnLeft(int16_t degrees)
{

  int16_t left = encoders.getCountsLeft();
  while(left > -(FULL_360 * ( degrees / 360.0)))
      {
        motors.setSpeeds(-75, 0);
        left = encoders.getCountsLeft();

        display.clear();
        display.print(left);

        
      }

      reset();

      
}

void drawSquare()
{
  for(int i = 0; i < 4; i++)
  {
    goForward(300);
  
    turnRight(90);
  }
  
}


//5125 360 deg

void drawLine()
{
  goForward(300);

  turnRight(360);

  goForward(300);
}

void drawA()
{ 
  turnRight(30);
  
  goForward(500);
  
  turnRight(120);
  
  goForward(250);
  
  turnRight(120);
  
  goForward(275);
  
  goBackward(275);
  
  turnLeft(120);
  
  goForward(300);
  
  turnLeft(60);
  
  goForward(200);
  
  turnLeft(90);

}

void drawB()
{
  goForward(400);

  turnRight(90);

  goForward(100);

  turnRight(45);

  goForward(50);

  turnRight(45);

  goForward(75);

  turnRight(45);

  goForward(50);

  turnRight(45);

  goForward(100);

  turnRight(180);

  goForward(100);

  turnRight(45);

  goForward(50);

  turnRight(45);

  goForward(75);

  turnRight(45);

  goForward(50);

  turnRight(45);

  goForward(100);
  
  turnRight(180);

  goForward(350);

  turnLeft(90);
  
}

void drawR()
{
  goForward(450);

  turnRight(90);

  goForward(110);

  turnRight(45);

  goForward(70);

  turnRight(45);

  goForward(100);

  turnRight(45);

  goForward(50);

  turnRight(45);

  goForward(120);

  turnLeft(135);

  goForward(300);

  turnLeft(48);

  goForward(200);

  turnLeft(90);
}

//ends at top not bottom
void drawS()
{
  goForward(50);

  turnRight(135);

  goForward(45);

  turnLeft(44);

  goForward(200);

  turnLeft(45);

  goForward(45);

  turnLeft(47);

  goForward(195);

  turnLeft(46);

  goForward(45);

  turnLeft(46);

  goForward(200);

  turnRight(45);

  goForward(45);

  turnRight(46);

  goForward(175);

  turnRight(45);

  goForward(45);

  turnRight(46);

  goForward(200);

  turnRight(45);

  goForward(45);

  turnLeft(45);

  goForward(200);
}

//starts at top
void drawE()
{
  goForward(195);

  goBackward(195);

  turnRight(90);

  goForward(220);

  turnLeft(90);

  goForward(195);

  goBackward(195);

  turnRight(90);

  goForward(220);

  turnLeft(90);

  goForward(195);

  goBackward(195);
  
  
}
void loop() {

    int16_t countsLeft = encoders.getCountsLeft();
    int16_t countsRight = encoders.getCountsRight();
  
  // put your main code here, to run repeatedly:

    if(buttonA.isPressed())
    {
      delay(1000);
      drawR();
      drawS();
      drawE();
      
    }

    if(buttonB.isPressed())
    {
      delay(1000);
      drawSquare();
    }

    if(buttonC.isPressed())
    {
      delay(1000);
      drawLine();
    }


    static uint8_t lastDisplayTime;

    if ((uint8_t)(millis() - lastDisplayTime) >= 100)
    {
      lastDisplayTime = millis();
      
      lastDisplayTime = millis();
      display.clear();
      display.print(countsLeft);
      display.gotoXY(0, 1);
      display.print(countsRight);
    }
  

  

}

/***************************************************
 * GAME = PressLeft.
 * Code made by Captaindavid73.
 * All original code from CaptainDavid73.
 * Feel free to use this code for a project similar to this project.
 ***************************************************/

/***************************************************
______________________PINOUT______________________
LEDS :
12 : BLUELED
11 : BLUELED
10 : GREENLED
9 : GREENLED
8 : YELLOWLED
7 : YELLOWLED
6 : REDLED
5 : REDLED
4 : WHITELED
3 : WHITELED

BUZZER : 2
BUTTON : 13
***************************************************/

#include <Arduino.h> //working with VSCODE/PLATFORMIO requires arduino library.

//declare the voids for all the levels, and or states.
void staticAnimation();
void transitionAnimation();
void firstLevel();
void secondLevel();
void thirdLevel();
void fourthLevel();
void fifthLevel();
void endAnimation();
int firstWin;
int secondWin;
int thirdWin;
int fourthWin;
int fifthWin;
int endCounter;

//declare an interger for the static animation counter
int j;

//declare the state for the LEDS to be low.
int ledState = LOW;

//declare the intergers for the blink with no delay, so that the button does not get affected by the delay of the blinking from the LEDS.
unsigned long previousMillis = 0; 
int long interval;

//declare contstants for the LEDS as an array for neatness.
const int LED [] {
  12, 11, 10, 9, 8, 7, 6, 5, 4, 3
};

//declare contstants the other components like button and buzzer.
const int buttonPin = 13;
const int buzzerPin = 2;

//declare intergers for the value of the components.
int buttonVal;
int buzzerTone = 0;
int counter;
int soundTime;

void setup(){
  //begin serial monitor to look at the values.
  Serial.begin(9600);

  //init the button and set it on pullup to set the default to 1.
  pinMode(buttonPin, INPUT_PULLUP);

  //init the buzzer for special sounds.
  pinMode(buzzerPin, OUTPUT);

  //init all the leds with a for loop to let the compiler understand that LEDS is an array.
  for(int i = 0; i < 10; i++){
    pinMode(LED[i], OUTPUT);
  }
}

void loop(){
  //all the controls of the button and the readout on the serial monitor are done here.
  buttonVal = digitalRead (buttonPin);
  if(counter == 0){
  if(buttonVal == 0){
    counter = 1;
    delay(1000);
    tone(buzzerPin, 1319);
    }
    else{
      noTone(buzzerPin);
    }
  }
  Serial.print(" COUNTER = ");
  Serial.print(counter);
  Serial.print(" LEDSTATE = ");
  Serial.print(ledState);
  Serial.print(" BUTTONVAL = ");
  Serial.println(buttonVal);

  //a little script to make sure the LEDS can blink without delay, so i does not interfere with the button.
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;

    if(ledState == LOW){
      ledState = HIGH;
    }
    else{
      ledState = LOW;
    }
  }

  //init the static animation when the button has not been pressed yet.
  if(counter == 0){
    staticAnimation();
  }
  
  //all these ifs are for the counter corrosponding with the level, which is called up in the main loop of the code.
  if(counter == 1){
    transitionAnimation();
  }
  if(counter == 2){
    firstLevel();
  }
  if(counter == 3){
    secondLevel();
  }
  if(counter == 4){
    thirdLevel();
  }
  if(counter == 5){
    fourthLevel();
  }
  if(counter == 6){
    fifthLevel();
  }
  if(counter == 7){
    endAnimation();
  }
}

void staticAnimation(){
  //everything is done inside this for loop, the for loop acts as a counter to indicate when the LEDS have to blink.
  for(j = 1; j < 301; j = j + 1){
    if(j <= 30){
      digitalWrite(LED[0], HIGH);
    }
    else{
      digitalWrite(LED[0], LOW);
    }
    if(j > 30 && j <= 60){
      digitalWrite(LED[2], HIGH);
    }
    else{
      digitalWrite(LED[2], LOW);
    }
    if(j > 60 && j <= 90){
      digitalWrite(LED[4], HIGH);
    }
    else{
      digitalWrite(LED[4], LOW);
    }
    if(j > 90 && j <= 120){
      digitalWrite(LED[6], HIGH);
    }
    else{
      digitalWrite(LED[6], LOW);
    }
    if(j > 120 && j <= 150){
      digitalWrite(LED[8], HIGH);
    }
    else{
      digitalWrite(LED[8], LOW);
    }
    if(j > 150 && j <= 180){
      digitalWrite(LED[9], HIGH);
    }
    else{
      digitalWrite(LED[9], LOW);
    }
    if(j > 180 && j <= 210){
      digitalWrite(LED[7], HIGH);
    }
    else{
      digitalWrite(LED[7], LOW);
    }
    if(j > 210 && j <= 240){
      digitalWrite(LED[5], HIGH);
    }
    else{
      digitalWrite(LED[5], LOW);
    }
    if(j > 240 && j <= 270){
      digitalWrite(LED[3], HIGH);
    }
    else{
      digitalWrite(LED[3], LOW);
    }
    if(j > 270 && j <= 299){
      digitalWrite(LED[1], HIGH);
    }
    else{
      digitalWrite(LED[1], LOW);
    }
    Serial.println(j);
  }
}

void transitionAnimation(){
  //this loop runs inside a for loop that counts to 10, if it reaches 10 it will instantly move to the first level.
for(soundTime = 1; soundTime < 11; soundTime = soundTime +1){
  if(soundTime <= 5){
    buzzerTone = 988;
    tone(buzzerPin, buzzerTone);
    digitalWrite(LED[0], HIGH);
    digitalWrite(LED[3], HIGH);
    digitalWrite(LED[4], HIGH);
    digitalWrite(LED[7], HIGH);
    digitalWrite(LED[8], HIGH);
  }
  else{
    digitalWrite(LED[0], LOW);
    digitalWrite(LED[3], LOW);
    digitalWrite(LED[4], LOW);
    digitalWrite(LED[7], LOW);
    digitalWrite(LED[8], LOW);
    digitalWrite(buzzerPin, LOW);
  }
  if(soundTime > 5 && soundTime <=9){
    buzzerTone = 1319;
    tone(buzzerPin, buzzerTone);
    digitalWrite(LED[1], HIGH);
    digitalWrite(LED[2], HIGH);
    digitalWrite(LED[5], HIGH);
    digitalWrite(LED[6], HIGH);
    digitalWrite(LED[9], HIGH);
  }
  else{
    digitalWrite(buzzerPin, LOW);
    digitalWrite(LED[1], LOW);
    digitalWrite(LED[2], LOW);
    digitalWrite(LED[5], LOW);
    digitalWrite(LED[6], LOW);
    digitalWrite(LED[9], LOW);
  }
  if(soundTime == 10){
    counter = 2;
    buttonVal = 1;
    noTone(buzzerPin);
  }
  Serial.print(" BUZZERTONE = ");
  Serial.print(buzzerTone);
  Serial.print(" SOUNDTIME = ");
  Serial.println(soundTime);
  }
}

void firstLevel(){
  //set the speed of the interval to a 500 for an easy first level.
  interval = 500;
  //set it so that if you fail the first level you start at level 1 again.
  if(buttonVal == 0 && ledState == 1){
    counter = 0;
    buttonVal = 1;
  }
  
  //blink the LEDS using the blinkwithoutdelay method.
  digitalWrite(LED[0], ledState);
  if(ledState == 0){
    digitalWrite(LED[1], HIGH);
  }
  else{
    digitalWrite(LED[1], LOW);
  }

  //if you hit the LEDS correctly it will play a nice animation and moves on to the second level.
  if(buttonVal == 0 && ledState == 0){
    for(firstWin = 1; firstWin < 101; firstWin = firstWin + 1){
      if(firstWin <= 25){
        digitalWrite(LED[0], HIGH);
        digitalWrite(LED[1], HIGH);
      }
      else{
        digitalWrite(LED[0], LOW);
        digitalWrite(LED[1], LOW);
      }
      if(firstWin > 25 && firstWin <= 50){
        digitalWrite(LED[0], LOW);
        digitalWrite(LED[1], LOW);
      }
      if(firstWin > 50 && firstWin <= 75){
        digitalWrite(LED[0], HIGH);
        digitalWrite(LED[1], HIGH);
      }
      else{
        digitalWrite(LED[0], LOW);
        digitalWrite(LED[1], LOW);
      }
      if(firstWin > 75 && firstWin <= 99){
        digitalWrite(LED[0], LOW);
        digitalWrite(LED[1], LOW);
      }
      if(firstWin == 100){
        counter = 3;
        buttonVal = 1;
      }
      Serial.println(firstWin);
    }
  }
}

void secondLevel(){
  //set the speed for the second level.
  interval = 400;

  //if you fail to hit the button incorrectly it will send you to stage one.
  if(buttonVal == 0 && ledState == 1){
    counter = 1;
    buttonVal = 1;
  }
  
  //blink the LEDS using the blinkwithoutdelay method.
  digitalWrite(LED[2], ledState);
  if(ledState == 0){
    digitalWrite(LED[3], HIGH);
  }
  else{
    digitalWrite(LED[3], LOW);
  }

  //if you hit the button correctly it will send you to the next stage with an animation.
  if(buttonVal == 0 && ledState == 0){
    for(secondWin = 1; secondWin < 101; secondWin = secondWin + 1){
      if(secondWin <= 25){
        digitalWrite(LED[2], HIGH);
        digitalWrite(LED[3], HIGH);
      }
      else{
        digitalWrite(LED[2], LOW);
        digitalWrite(LED[3], LOW);
      }
      if(secondWin > 25 && secondWin <= 50){
        digitalWrite(LED[2], LOW);
        digitalWrite(LED[3], LOW);
      }
      if(secondWin > 50 && secondWin <= 75){
        digitalWrite(LED[2], HIGH);
        digitalWrite(LED[3], HIGH);
      }
      else{
        digitalWrite(LED[2], LOW);
        digitalWrite(LED[3], LOW);
      }
      if(secondWin > 75 && secondWin <= 99){
        digitalWrite(LED[2], LOW);
        digitalWrite(LED[3], LOW);
      }
      if(secondWin == 100){
        counter = 4;
        buttonVal = 1;
      }
      Serial.println(secondWin);
    }
  }
}

void thirdLevel(){
  //set the speed for the second level.
  interval = 250;

  //if you fail to hit the button incorrectly it will send you to stage one.
  if(buttonVal == 0 && ledState == 1){
    counter = 1;
    buttonVal = 1;
  }
  
  //blink the LEDS using the blinkwithoutdelay method.
  digitalWrite(LED[4], ledState);
  if(ledState == 0){
    digitalWrite(LED[5], HIGH);
  }
  else{
    digitalWrite(LED[5], LOW);
  }

  //if you hit the button correctly it will send you to the next stage with an animation.
  if(buttonVal == 0 && ledState == 0){
    for(thirdWin = 1; thirdWin < 101; thirdWin = thirdWin + 1){
      if(thirdWin <= 25){
        digitalWrite(LED[4], HIGH);
        digitalWrite(LED[5], HIGH);
      }
      else{
        digitalWrite(LED[4], LOW);
        digitalWrite(LED[5], LOW);
      }
      if(thirdWin > 25 && thirdWin <= 50){
        digitalWrite(LED[4], LOW);
        digitalWrite(LED[5], LOW);
      }
      if(thirdWin > 50 && thirdWin <= 75){
        digitalWrite(LED[4], HIGH);
        digitalWrite(LED[5], HIGH);
      }
      else{
        digitalWrite(LED[4], LOW);
        digitalWrite(LED[5], LOW);
      }
      if(thirdWin > 75 && thirdWin <= 99){
        digitalWrite(LED[4], LOW);
        digitalWrite(LED[5], LOW);
      }
      if(thirdWin == 100){
        counter = 5;
        buttonVal = 1;
      }
      Serial.println(thirdWin);
    }
  }
}

void fourthLevel(){
  //set the speed for the second level.
  interval = 200;

  //if you fail to hit the button incorrectly it will send you to stage one.
  if(buttonVal == 0 && ledState == 1){
    counter = 1;
    buttonVal = 1;
  }
  
  //blink the LEDS using the blinkwithoutdelay method.
  digitalWrite(LED[6], ledState);
  if(ledState == 0){
    digitalWrite(LED[7], HIGH);
  }
  else{
    digitalWrite(LED[7], LOW);
  }

  //if you hit the button correctly it will send you to the next stage with an animation.
  if(buttonVal == 0 && ledState == 0){
    for(fifthWin = 1; fifthWin < 101; fifthWin = fifthWin + 1){
      if(fifthWin <= 25){
        digitalWrite(LED[6], HIGH);
        digitalWrite(LED[7], HIGH);
      }
      else{
        digitalWrite(LED[6], LOW);
        digitalWrite(LED[7], LOW);
      }
      if(fifthWin > 25 && fourthWin <= 50){
        digitalWrite(LED[6], LOW);
        digitalWrite(LED[7], LOW);
      }
      if(fifthWin > 50 && fifthWin <= 75){
        digitalWrite(LED[6], HIGH);
        digitalWrite(LED[7], HIGH);
      }
      else{
        digitalWrite(LED[6], LOW);
        digitalWrite(LED[7], LOW);
      }
      if(fifthWin > 75 && fifthWin <= 99){
        digitalWrite(LED[6], LOW);
        digitalWrite(LED[7], LOW);
      }
      if(fifthWin == 100){
        counter = 6;
        buttonVal = 1;
      }
      Serial.println(fifthWin);
    }
  }
}

void fifthLevel(){
  //set the speed for the second level.
  interval = 150;

  //if you fail to hit the button incorrectly it will send you to stage one.
  if(buttonVal == 0 && ledState == 1){
    counter = 1;
    buttonVal = 1;
  }
  
  //blink the LEDS using the blinkwithoutdelay method.
  digitalWrite(LED[8], ledState);
  if(ledState == 0){
    digitalWrite(LED[9], HIGH);
  }
  else{
    digitalWrite(LED[9], LOW);
  }

  //if you hit the button correctly it will send you to the next stage with an animation.
  if(buttonVal == 0 && ledState == 0){
    for(fifthWin = 1; fifthWin < 101; fifthWin = fifthWin + 1){
      if(fifthWin <= 25){
        digitalWrite(LED[8], HIGH);
        digitalWrite(LED[9], HIGH);
      }
      else{
        digitalWrite(LED[8], LOW);
        digitalWrite(LED[9], LOW);
      }
      if(fifthWin > 25 && fifthWin <= 50){
        digitalWrite(LED[8], LOW);
        digitalWrite(LED[9], LOW);
      }
      if(fifthWin > 50 && fifthWin <= 75){
        digitalWrite(LED[8], HIGH);
        digitalWrite(LED[9], HIGH);
      }
      else{
        digitalWrite(LED[8], LOW);
        digitalWrite(LED[9], LOW);
      }
      if(fifthWin > 75 && fifthWin <= 99){
        digitalWrite(LED[8], LOW);
        digitalWrite(LED[9], LOW);
      }
      if(fifthWin == 100){
        counter = 7;
        buttonVal = 1;
      }
      Serial.println(fifthWin);
    }
  }
}

void endAnimation(){
  //if you hit the counter on 7, aka get to the last level, it will play a little animation with a tune, and send you back right to the start.
  for(endCounter = 0; endCounter < 401; endCounter = endCounter + 1){
    if(endCounter <= 60){
      buzzerTone = 1319;
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], HIGH);
      tone(buzzerPin, buzzerTone);
    }
    else{
      noTone(buzzerPin);
    }
    if(endCounter > 60 && endCounter <= 120){
      buzzerTone = 988;
      tone(buzzerPin, buzzerTone);
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[3], HIGH);
    }
    else{
      noTone(buzzerPin);
    }
    if(endCounter > 120 && endCounter <= 180){
      buzzerTone = 1319;
      tone(buzzerPin, buzzerTone);
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[3], HIGH);
      digitalWrite(LED[4], HIGH);
      digitalWrite(LED[5], HIGH);
    }
    else{
      noTone(buzzerPin);
    }
    if(endCounter > 180 && endCounter <= 240){
      buzzerTone = 1319;
      tone(buzzerPin, buzzerTone);
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[3], HIGH);
      digitalWrite(LED[4], HIGH);
      digitalWrite(LED[5], HIGH);
      digitalWrite(LED[6], HIGH);
      digitalWrite(LED[7], HIGH);
    }
    else{
      noTone(buzzerPin);
    }
    if(endCounter > 240 && endCounter <= 300){
      buzzerTone = 988;
      tone(buzzerPin, buzzerTone);
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[3], HIGH);
      digitalWrite(LED[4], HIGH);
      digitalWrite(LED[5], HIGH);
      digitalWrite(LED[6], HIGH);
      digitalWrite(LED[7], HIGH);
      digitalWrite(LED[8], HIGH);
      digitalWrite(LED[9], HIGH);
    }
    else{
      noTone(buzzerPin);
    }
    if(endCounter > 300 && endCounter <= 330){
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], LOW);
      digitalWrite(LED[3], LOW);
      digitalWrite(LED[4], LOW);
      digitalWrite(LED[5], LOW);
      digitalWrite(LED[6], LOW);
      digitalWrite(LED[7], LOW);
      digitalWrite(LED[8], LOW);
      digitalWrite(LED[9], LOW);
    }
    if(endCounter > 330 && endCounter <= 399){
      buzzerTone = 1319;
      tone(buzzerPin, buzzerTone);
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[3], HIGH);
      digitalWrite(LED[4], HIGH);
      digitalWrite(LED[5], HIGH);
      digitalWrite(LED[6], HIGH);
      digitalWrite(LED[7], HIGH);
      digitalWrite(LED[8], HIGH);
      digitalWrite(LED[9], HIGH);
    }
    else{
      noTone(buzzerPin);
    }
    if(endCounter == 400){
      counter = 0;
      buttonVal = 1;
    }
    Serial.println(endCounter);
  }
}

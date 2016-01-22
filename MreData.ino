#include <SPI.h>
#include <EEPROM.h>
#include "Arduboy.h"
#include "bitmaps.h"
#include "Character.h"
#include "Weapons.h"
#include "physics.h"
#include <stdio.h>

bool gameState = 1;

Arduboy display;
Character belknar('a', 3, 1, 10, Rect{32,64,8,8});
//Character starLord('g', 3, 1, 300, Rect{5,0,8,8});
Character starLord1('g', 3, 1, 1200, Rect{5,24,8,8});
Character starLord2('g', 3, 1, 1900, Rect{5,48,8,8});
Character starLord3('g', 3, 1, 1400, Rect{5,72,8,8});
Character starLord4('g', 3, 1, 1700, Rect{5,96,8,8});
//Character starLord5('g', 3, 1, 300, Rect{5,120,8,8});


Weapons weapon;

void setup() {
  SPI.begin();
  display.start();
  display.setTextSize(1);
  display.clearDisplay();
  // delay(2000);
  //intro bitmap
  introFade();
  //character creation example
}

void loop() {

  if(gameState){
    
  //debug(starLord.y,starLord.x);
  // enable directions to be implemented
  belknar.enableMovement(&belknar,&display, ship);
  // enable weapon system (at least A BUTTON for now)
  belknar.activateWeapons(&weapon ,&display, bomb);
  
//  starLord.addAi(&weapon,&belknar, &display, star, &gameState);
  starLord1.addAi(&weapon,&belknar, &display, star, &gameState);
  starLord2.addAi(&weapon,&belknar, &display, star, &gameState);
  starLord3.addAi(&weapon,&belknar, &display, star, &gameState);
  starLord4.addAi(&weapon,&belknar, &display, star, &gameState);
  //starLord5.addAi(&weapon,&belknar, &display, star, &gameState);

  display.display();

  display.clearDisplay();

  }else{
  gameOver();
  }

  
}


//isimple intro bitmap with fade effect
void introFade() {
  display.clearDisplay();
  display.drawBitmap(1, 1, mreData, 128, 64, WHITE);
  display.display();
  delay(2000);

  for (int x = 15; x < 140; x++ ) {
    for (int y = 0; y < 64; y++) {
      display.drawPixel(x, y, 0);
    }
    display.display();
    delay(5);
  }
  delay(1000);
  display.clearDisplay();
}

void debug(uint8_t x, uint8_t y) {
  display.setCursor(5, 5);
  display.write('y');
  display.setCursor(15, 5);
  display.print(x);
  display.setCursor(5, 15);
  display.write('x');
  display.setCursor(15, 15);
  display.print(y);
}

void gameOver(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 22);
  display.write('G');
    display.setCursor(15, 22);
  display.write('A');
    display.setCursor(30, 22);
  display.write('M');
    display.setCursor(45, 22);
  display.write('E');
    display.setCursor(70, 22);
  display.write('O');
    display.setCursor(85, 22);
  display.write('V');
    display.setCursor(100, 22);
  display.write('E');
    display.setCursor(115, 22);
  display.write('R');
  display.display();
  
}


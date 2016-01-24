#include <SPI.h>
#include <EEPROM.h>
#include "Arduboy.h"
#include "bitmaps.h"
#include "Character.h"
#include "Weapons.h"
#include "physics.h"
#include <stdio.h>
#include <math.h>

bool gameState = 1;

Arduboy display;
Character belknar( Rect{32, 64 , 8, 8});
Character starLord( Rect{5, 0, 8, 8});
Character starLord1( Rect{5, 24, 8, 8});
Character starLord2( Rect{5, 48, 8, 8});
Character starLord3( Rect{5, 72, 8, 8});
Character starLord4(Rect{5, 96, 8, 8});
Character starLord5( Rect{5, 120, 8, 8});

Weapons weapon;

void setup() {
  SPI.begin();
  display.start();
  display.setTextSize(1);
  display.clearDisplay();
  // delay(2000);
  //intro bitmap
  introFade();
  //display.tunes.playScore(score);
}

void loop() {

  if (!(display.nextFrame())) {
    return;
  }

  if (gameState) {
    // count frames
    weapon.countFrames++;
    // disply kill count
    debug(belknar.killCount);
    // enable directions to be implemented
    belknar.enableMovement(&belknar, &display, ship);
    // enable weapon system (at least A BUTTON for now)
    belknar.activateWeapons( &display, bomb);

    // ATTACK phase
    if (weapon.countFrames > 2) {
      starLord1.aiAttackFormation(&belknar, &display, star, &gameState);
    }
    if (weapon.countFrames > 25) {
      starLord2.aiAttackFormation(&belknar, &display, star, &gameState);
    }
    if (weapon.countFrames > 50) {
      starLord3.aiAttackFormation(&belknar, &display, star, &gameState);
    }
    if (weapon.countFrames > 75) {
      starLord4.aiAttackFormation(&belknar, &display, star, &gameState);
    }
    if (weapon.countFrames > 100) {
      starLord.aiAttackFormation(&belknar, &display, star, &gameState);
    }
    if (weapon.countFrames > 125) {
      starLord5.aiAttackFormation(&belknar, &display, star, &gameState);
    }

    // another type of attack
   // starLord6.addAi( &belknar, &display, star, &gameState);
    display.display();

    display.clearDisplay();

  } else {
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
//
//void debug(unsigned long x, uint8_t y, uint8_t z, uint8_t j) {
//  display.setCursor(5, 5);
//  display.write('y');
//  display.setCursor(15, 5);
//  display.print(x);
//  display.setCursor(5, 15);
//  display.write('x');
//  display.setCursor(15, 15);
//  display.print(y);
//  display.setCursor(5, 25);
//  display.write('z');
//  display.setCursor(15, 25);
//  display.print(z);
//  display.setCursor(5, 35);
//  display.write('j');
//  display.setCursor(15, 35);
//  display.print(j);
//}
void debug(uint8_t x) {
  display.setCursor(64, 5);
  display.print(x);
}

void gameOver() {
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



#include <SPI.h>
#include <EEPROM.h>
#include "Arduboy.h"
#include "bitmaps.h"
#include "Character.h"
#include "Weapons.h"
#include <stdio.h>

Arduboy display;
Character belknar('a', 3, 1, 32, 64, 8, 8, 10);
Weapons weapon;

unsigned long aiInterval = 40;
unsigned long aiPreMillis = 0;

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
  debug(weapon.x, weapon.y);
  // enable directions to be implemented
  belknar.enableMovement(&belknar,&display, star);
  // enable weapon system (at least A BUTTON for now)
  belknar.activateWeapons(&weapon ,&display);

  display.display();

  display.clearDisplay();
}


//isimple intro bitmap with fade effect
void introFade() {
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
void reset(uint8_t * r) {

  if (*r > 64) {
    *r = 0;
  }
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


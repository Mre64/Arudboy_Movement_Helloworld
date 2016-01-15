#include <SPI.h>
#include <EEPROM.h>
#include "Arduboy.h"
#include "bitmaps.h"
#include "Charater.h"
#include <stdio.h>

void animateCharacter(Character c, unsigned char bitmap[]);

Arduboy display;

uint8_t curX = 30;
uint8_t curY = 30;

void setup() {
    SPI.begin();
    display.start();
    display.setTextSize(1);
    display.clearDisplay();
    delay(2000);
    //intro bitmap
    introFade();
    //character creation example
    Character c = createcharacter('a', 3, 1, 10, 20, 10, 10);
}

void loop() {
  display.setCursor(5,5);
  display.write('y');
  display.setCursor(15,5);
  display.print(curX);
  display.setCursor(5,15);
  display.write('x');
  display.setCursor(15,15);
  display.print(curY);
  display.drawBitmap(curY,curX,star,8,8,WHITE);
 // display.drawRect(40,40,10,10,WHITE);
  display.display();
  
 if (display.pressed(UP_BUTTON) && (curX > 0)){
      delay(15);
        curX--;
        }else if(display.pressed(DOWN_BUTTON) && (curX < 57)){
      delay(15);
        curX++;
        }else if(display.pressed(LEFT_BUTTON) && (curY > 0)){
      delay(15);
        curY--;
        }else if(display.pressed(RIGHT_BUTTON) && (curY < 121)){
      delay(15);
        curY++;
        }
        
  display.clearDisplay();  
}

// I would like to have a character created WITH bitmap, however I am having trouble with bitmap a fucntion parameter.
void animateCharacter(Character c, unsigned char b[]){
  display.drawBitmap(c.dimX,c.dimY,b,c.dimH,c.dimW,WHITE);
}

//isimple intro bitmap with fade effect
void introFade(){
    display.drawBitmap(1,1,mreData,128,64,WHITE);
    display.display();
    delay(2000); 
    
    for(int x = 15; x < 140; x++ ){
      for(int y = 0; y < 64; y++){
        display.drawPixel(x,y,0);
      }
      display.display();
      delay(5);
    }
    delay(1000);
    display.clearDisplay();
}

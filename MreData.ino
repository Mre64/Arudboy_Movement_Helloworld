#include <SPI.h>
#include <EEPROM.h>
#include "Arduboy.h"
#include "bitmaps.h"
#include "Charater.h"
#include <stdio.h>

void animateCharacter(Character c, unsigned char bitmap[]);

Arduboy display;

uint8_t aiX = 30;
uint8_t aiY = 0;
uint8_t curX = 30;
uint8_t curY = 30;
uint8_t amoX;
uint8_t amoY;


const uint8_t xBound = 120;
const uint8_t yBound = 56;
const uint8_t zBound = 0;

unsigned long aiInterval = 40;
unsigned long aiPreMillis = 0;
unsigned long mreInterval = 20;
unsigned long mrePreMillis = 0;
unsigned long ammoInterval = 20;
unsigned long ammoPreMillis = 0;

unsigned long mreCurMillis;

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
    debug(curX,curY);
    
    amoX = curX +4;
    amoY = curY +4;
    
    display.drawBitmap(curY,curX,star,8,8,WHITE);
    display.drawBitmap(30,aiY,star,8,8,WHITE);
    display.drawPixel(amoY, amoX,WHITE);
    
    display.display();
    
    unsigned long currentMillis = millis();
    moveAi(&currentMillis,&aiPreMillis,&aiInterval, &aiY);
    
    if (display.pressed(UP_BUTTON) && (curX > zBound)){
        mreCurMillis = millis();
        if(mreCurMillis - mrePreMillis > mreInterval) {
            mrePreMillis = mreCurMillis;
            curX--;
        }
        }else if(display.pressed(DOWN_BUTTON) && (curX < yBound)){
        mreCurMillis = millis();
        
        if(mreCurMillis - mrePreMillis > mreInterval) {
            mrePreMillis = mreCurMillis;
            curX++;
        }
        }else if(display.pressed(LEFT_BUTTON) && (curY > zBound)){
        mreCurMillis = millis();
        if(mreCurMillis - mrePreMillis > mreInterval) {
            mrePreMillis = mreCurMillis;
            curY--;;
        }
        }else if(display.pressed(RIGHT_BUTTON) && (curY < xBound)){
        mreCurMillis = millis();
        
        if(mreCurMillis - mrePreMillis > mreInterval) {
            mrePreMillis = mreCurMillis;
            curY++;
        }
    }

    if (display.pressed(A_BUTTON)){
       unsigned long ammoCurMillis = millis();
        if(ammoCurMillis - ammoPreMillis > ammoInterval) {
            ammoPreMillis = ammoCurMillis;
            amoY--;
        }
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
void reset(uint8_t * r){
    
    if(*r > 64){
        *r = 0;
    }
}

void debug(uint8_t x, uint8_t y){
    display.setCursor(5,5);
    display.write('y');
    display.setCursor(15,5);
    display.print(x);
    display.setCursor(5,15);
    display.write('x');
    display.setCursor(15,15);
    display.print(y);
}

void moveAi(unsigned long * currentMillis, unsigned long * aiPreMillis, unsigned long * aiInterval, uint8_t * r){
    
    if(* currentMillis - * aiPreMillis > * aiInterval) {
        * aiPreMillis = * currentMillis;
        reset(r);
        
        aiY++;
    }
}

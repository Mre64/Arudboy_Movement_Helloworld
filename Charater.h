#include <avr/pgmspace.h>
#ifndef CHARACTER_H
#define CHARACTER_H

   struct Character {
   char  characterClass;
   uint8_t strength;
   bool  destructable;
   uint8_t dimX;
   uint8_t dimY;
   uint8_t dimH;
   uint8_t dimW;
};

// how I would like to assign new character objects, similar to JS style if that makes sense
Character createcharacter(char characterClass, uint8_t strength, bool destructable, uint8_t dimX, uint8_t dimY, uint8_t dimH, uint8_t dimW){
  Character character;
  character.characterClass = characterClass;
  character.strength = strength;
  character.destructable = destructable;
  character.dimX = dimX;
  character.dimY = dimY;
  return character;
}
// simple getter
char getcharacterClass(struct Character b){
    return b.characterClass;
}

#endif

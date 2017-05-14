// Maria Beatriz Zanardo
// Lab 2, Part 2
// Interface for got class

#ifndef GOT_H
#define GOT_H

#include <string>
#include "character.h"

using namespace std;

class Got : public Character {		// Class representing characters from the show "Game of Thrones".
  public:
    Got(string = "empty", string = "empty");
    virtual void catchphrase(); 
};

#endif

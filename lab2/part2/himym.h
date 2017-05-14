// Maria Beatriz Zanardo
// Lab 2, Part 2
// Interface for Himym class

#ifndef HIMYM_H
#define HIMYM_H

#include <string>
#include "character.h"

using namespace std;

class Himym : public Character {	// Class representing characters from the show "How I Met Your Mother".  
  public: 
    Himym (string = "empty", string = "empty");
    virtual void catchphrase();
};

#endif

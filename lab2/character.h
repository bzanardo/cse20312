// Maria Beatriz Zanado
// Lab 2, Part 2
// Interface for character class

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class Character {
  public:
    Character(string = "empty", string = "empty");  // Constructor
    virtual void catchphrase() = 0;
    string getName();

  private:
    string firstname;
    string lastname;
};

#endif

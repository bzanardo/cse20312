// Maria Beatriz Zanado
// Lab 2, Part 2
// Interface for character class

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class Character { 	// Class for TV characters
  public:
    Character(string = "empty", string = "empty");
    virtual void catchphrase() = 0;
    string getFirstName();
    string getLastName();
  private:
    string firstname;
    string lastname;
};

#endif

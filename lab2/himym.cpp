// Maria Beatriz Zanardo
// Lab 2, Part 2
// Implementation for the Himym class

#include <iostream>
#include <string>
#include "character.h"
#include "himym.h"

Himym::Himym (string fname, string lname) : (string fname, string lname) {
}

void Himym::catchphrase() {
  cout << "Suit up!" << endl; 
  cout << "Character name: " << getFirstName() << " " << getLastName() << endl;

}

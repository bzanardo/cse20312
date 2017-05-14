// Maria Beatriz Zanardo
// Lab 2, Part 2
// Implementation for Character class

#include <iostream>
#include <string>
#include "character.h"

using namespace std;

Character::Character (string fname, string lname) {

  firstname = fname;
  lastname = lname;

}

void Character::catchphrase() {
  
  cout << "Character name: " << firstname << " " << lastname << endl;
}

string Character::getFirstName() {
  return(firstname);
}

string Character::getLastName() {
  return(lastname);
}

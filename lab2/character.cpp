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
  
  cout << "Character name: " << firsname << " " << lastname << endl;
}

string getFirstName() {
  return(firstname);
}

string getLastName() {
  return(lastname);
}

// Maria Beatriz Zanardo
// Lab 2, Part 2
// Implemention for Got class

#include <iostream>
#include <string>
#include "character.h"
#include "got.h"

using namespace std;

Got::Got(string firstname, string lastname): Character (firstname, lastname) {
}

void Got::catchphrase() {
  cout << "Winter is coming." << endl;
  cout << "Character name: " << getFirstName() << " " << getLastName() << endl;
}

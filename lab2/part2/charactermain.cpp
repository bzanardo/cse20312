// Maria Beatriz Zanardo
// Lab 2, Part 2

#include "character.h"
#include "got.h"
#include "himym.h"

using namespace std;

int main() {
  Got c1 ("Jon", "Snow");
  Got c2 ("Tyrion", "Lannister");
  Got c3 ("Sansa", "Stark");
  Himym c4 ("Barney", "Stinson");
  Himym c5 ("Ted", "Mosby");
  Himym c6 ("Robin", "Scherbatsky");

  Got * c1_ptr = &c1;
  Got * c2_ptr = &c2;
  Got * c3_ptr = &c3;
  Himym * c4_ptr = &c4;
  Himym * c5_ptr = &c5;
  Himym * c6_ptr = &c6;

  c1_ptr->catchphrase();
  c2_ptr->catchphrase();
  c3_ptr->catchphrase();
  c4_ptr->catchphrase();
  c5_ptr->catchphrase();
  c6_ptr->catchphrase();
}

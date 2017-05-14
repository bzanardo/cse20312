// Maria Beatriz Zanardo
// Lab 1
// Interface for C4Board class

#include "c4col.h"

class C4Board {
  public:
    C4Board();
    ~C4Board();
    void display();
    void play();
  private:
    int numcol;
    C4Col board[7];
    bool check(char);
};

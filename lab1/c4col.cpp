// Maria Beatriz Zanardo
// Lab 1
// Implementation for C4Col Class

#include "c4col.h"
#include <iostream>

using namespace std;

C4Col::C4Col() {
  maxDiscs = 6;
  numDiscs = 0;
  //ptr = new char[6]; 

  for (int i = 0; i <= 6; i++) {
    col[i] = ' ';
    //ptr[i] = ' ';
  }
}

C4Col::~C4Col() {
  //delete[] ptr;
}

int C4Col::isFull() {
  if (maxDiscs == numDiscs) {
    return (1);
  }
  else
    return (0);
}

char C4Col::getDisc(int n) {
  
  char c;
  if ( (n > 6) | (n < 0) ) {
    cout << "Invalid parameter." << endl;
  }
  else {
    c = col[n];
    return (c);
  }
}

int C4Col::getMaxDiscs() {
  return (maxDiscs);
}

void C4Col::addDisc(char c) {
  if (numDiscs == maxDiscs) {
    cout << "This column is full." << endl;
  }
  else {
    col[numDiscs] = c;
    numDiscs++;
  }
}

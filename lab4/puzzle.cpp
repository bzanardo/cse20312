// Maria Beatriz Zanardo
// Lab 4
// Implementattion for Puzzle class

#include "puzzle.h"
#include <iostream>

using namespace std;

Puzzle::Puzzle() {
  for (int i = 0; i != 9; i++) {
    for (int j = 0; j != 9; j++) {
      arr[i][j] = 0;
    }
  }
}

Puzzle::~Puzzle() {}

void Puzzle::print() {
  for (int i = 0; i != 9; i++) {
    for (int j = 0; j != 9; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void Puzzle::addNum(int row, int col, int num) {
  arr[row][col] = num;
}

int Puzzle::getNum (int row, int col) {
  int num;
  num = arr[row][col];
  return (num);
}

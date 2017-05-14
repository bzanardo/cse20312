// Maria Beatriz Zanardo
// Lab 4
// Interface for Puzzle class

#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle {
  public:
    Puzzle();
    ~Puzzle();
    void addNum(int, int, int);
    void print();
    int getNum(int, int);
  private:
  int arr [9][9];
};

#endif

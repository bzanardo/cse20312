// Maria Beatriz Zanardo
// Lab 1
// Interface for C4Col class

#ifndef C4COL_H
#define C4COL_H

class C4Col {
  public:
    C4Col();
    ~C4Col();
    int isFull();
    char getDisc(int);
    int getMaxDiscs();
    void addDisc(char);
  private:
    int numDiscs;
    int maxDiscs;
    char col[6];
    //char *ptr;

};

#endif

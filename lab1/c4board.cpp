// Maria Beatriz Zanardo
// Lab 1
// Implementation of C4Board class

#include "c4board.h"
#include <iostream>

using namespace std;

C4Board::C4Board() {
  numcol = 7;
  C4Col board[7];
}

C4Board::~C4Board() { }

void C4Board::display() {

  cout << " ";

  for (int k = 0; k < numcol; k++) {
    cout << k << " ";
  }

  cout << endl;

  for (int i = board[0].getMaxDiscs() - 1; i >= 0; i--) {
    cout << "|"; 
    for (int j = 0; j < numcol; j++) {
      cout << board[j].getDisc(i) << "|";
    }
    cout << endl;
  }
}

void C4Board::play() {
  
  int i = 0;
  int col;
  cout << "To quit, enter -1." << endl;
  display();
  while(col != -1) {
    if ( (i%2)+1 == 1) {
      cout << "Player 1, choose a column: ";
      cin >> col;
      
      if (board[col].isFull() == 1) {
        cout << "This column is full." << endl;
      }
 
      if ( (col > 6) || (col < -2) ) {
        cout << "Invalid column number." << endl;
      }
    
      else {
        board[col].addDisc('O');
        i++;
        display();
        check('O');
        if (check('O') == false) {
          break;
        }
      }
    }
    else {
      cout << "Player 2, choose a column: ";
      cin >> col;

      if (board[col].isFull() == 1) {
        cout << "This column is full." << endl;
      }

      if ( (col > 6) || (col < -2) ) {
        cout << "Invalid column number." << endl;
      }

      else {
        board[col].addDisc('X');
        i++;
        display();
        check('X');
        if (check('X') == false) {
          break;
        }
      }
    }
  }
}

bool C4Board::check(char c) {
  int count, player;
  char d;

  if (c == 'O') {
    player = 1;
  }
  if (c == 'X') {
    player = 2;
  }

  for(int i = 0; i < 7; i++) {
    for(int j = 0; j < 6; j++) {
      count = 0;
      for(int k = 0; (j + k) != 6; k++) {  // Check vertical
        d = board[i].getDisc(j + k);
        if (d == c) {
          count++;
        }
        if (d != c) {
          count = 0;
        }
        if (count == 4) {
          cout << "Player " << player << " won." << endl;
          return(false); 
        } 
      }
      count = 0;
  
      for(int l = 0; (i + l) != 7; l++) {  // Check horizontal 
        d = board[i + l].getDisc(j);
        if (d == c) {
          count++;
        }
        if (d != c) {
          count = 0;
        }
        if (count == 4) {
          cout << "Player " << player << " won." << endl;
          return(false);
        }
      }
      count = 0;

      for(int m = 0; m != 3; m++) {   // Check diagonal
        if ( ( (i + m) <= 7) && ( (j + m) <= 6) ) {
          d = board[i+m].getDisc(j+m);
          if (d == c) {
            count++;
          }
          if (d != c) {
            count = 0;
          }
          if (count == 4) {
            cout << "Player " << player << " won." << endl;
            return(false);
          }
        }
      }
  
      for(int m = 0; m != 3; m++) {
        if ( ( (i - m) >= 0) && ( (j + m) <= 6) ) {
          d = board[i-m].getDisc(j+m);
          if (d == c) {
            count++;
          }
          if (d != c) {
            count = 0;
          }
          if (count == 4) {
            cout << "Player " << player << " won." << endl;
            return(false);
          }
        }
       }
    }
  }
  return(true);
}

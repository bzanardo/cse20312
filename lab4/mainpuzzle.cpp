// Maria Beatriz Zanardo
// Lab 4
// Main program

#include "puzzle.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void setPossibleValues (Puzzle, int SolArr [9][9][9]);
void setGrids (Puzzle, int SolArr [9][9][9]);
void check(Puzzle &, int SolArr [9][9][9]);
void checkSingr(Puzzle &, int SolArr [9][9][9]);
void checkSingc(Puzzle &, int SolArr [9][9][9]);
bool done(Puzzle);

int main(int argc, char *argv[]) {

  Puzzle a;
  string numstring, numline;
  vector<int> vnum;
  int num;
  ifstream ifs;
  int solutionArr [9][9][9];

  if (argc <= 1) {
    cout << "Error. Please enter the filename after the executable name." << endl; 
    cout << "Ex: sudoku puzzle.txt" << endl;
    return(1);
  }

  ifs.open(argv[1]); 

  while (getline(ifs, numline)) {
    stringstream ss(numline);
    while (getline(ss, numstring, ' ')) {
      num = stoi (numstring);
      vnum.push_back(num);
    }
  }  

  auto it = vnum.begin();
    for (int i = 0; i != 9; i++) {
      for (int j = 0; j != 9; j++) {
        a.addNum(i, j, *it);
        it++;
      }
    }  
  
  a.print();
  cout << endl;

  for (int i = 0; i != 9; i++) {	// Initialize solutions array
    for (int j = 0; j != 9; j++) {
      for(int k = 0; k != 9; k++) {
        solutionArr[i][j][k] = 1;
      }
    }
  }

  while (!done(a)) {
    setPossibleValues(a, solutionArr);
    setGrids(a, solutionArr);
    check(a, solutionArr);
    checkSingr(a, solutionArr);
    checkSingc(a, solutionArr);
  }

  cout << "Solution: " << endl;
  a.print();

  return 0;
}

void setPossibleValues (Puzzle a, int SolArr[9][9][9]) {
  for (int row = 0; row != 9; row++) {
    for (int col = 0; col != 9; col++) {
      int value;
      value = a.getNum(row, col);
      if (value != 0) {         //if a cell is filled 
        for (int p = 0; p != 9; p++) {
          SolArr[row][col][p] = 0;
        }
        for (int i = 0; i != 9; i++) {
          SolArr[row][i][value-1] = 0;
          SolArr[i][col][value-1] = 0;
        }
      }
    }
  }
}

void setGrids (Puzzle a, int SolArr[9][9][9]) {
  for (int row = 0; row < 9; row+=3) {
    for (int col = 0; col < 9; col+=3) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          int value;
          value = a.getNum(row+i, col+j);
          if (value != 0) {         // if a cell is filled 
            int highRangex = (2-i);
            int highRangey = (2-j);
            int lowRangex = highRangex - 2;
            int lowRangey = highRangey - 2;
            for (int x = lowRangex; x <= highRangex; x++) {
              for (int y = lowRangey; y <= highRangey; y++) {
                SolArr[row+i+x][col+j+y][value-1] = 0;
              }
            }
          }
        }
      }
    }
  }
}

void check(Puzzle &a, int arr[9][9][9]) {
  int numcounter;
  for (int row = 0; row != 9; row++) {
    for (int col = 0; col != 9; col++) {
      numcounter = 0; 	
      for (int p = 0; p != 9; p++) {
        if (arr[row][col][p] != 0) {
          numcounter++;
        }
      }
      if (numcounter == 1) {		//solution found
        for (int p = 0; p != 9; p++) {
          if (arr[row][col][p] != 0) {
            a.addNum(row, col, (p+1) );
          }
        }
      }       
    }
  }
}

void checkSingr(Puzzle &a, int arr[9][9][9]) {
  int counter, r, c, num;
  for (int p = 0; p != 9; p++) {
    for (int row = 0; row != 9; row++) {
      counter = 0;
      for (int col = 0; col != 9; col++) {
        num = a.getNum(row, col);
        setPossibleValues(a, arr);
        if (num == 0) {
          if (arr[row][col][p] != 0) {
            counter++;
            r = row;
            c = col;
           }
         }
      }
      if (counter == 1) {
        a.addNum(r, c, (p+1));
      }
    }
  }                   
}

void checkSingc(Puzzle &a, int arr[9][9][9]) {
  int counter, r, c, num;
  for (int p = 0; p != 9; p++) {
    for (int col = 0; col != 9; col++) {
       counter = 0; 
      for (int row = 0; row != 9; row++) {
        num = a.getNum(row, col);
        setPossibleValues(a, arr);
        if (num == 0) {
          if (arr[row][col][p] != 0) {
            counter++;
            r = row;
            c = col;
           }
         }
      }
      if (counter == 1) {
        a.addNum(r, c, (p+1));
      }
    }
  }                   
}

bool done(Puzzle a) {
  for (int i = 0; i != 9; i++) {
    for (int j = 0; j!= 9; j++) {
      if ( a.getNum(i, j) == 0) {
        return (false);
      }
    }
  }
  return(true);
}

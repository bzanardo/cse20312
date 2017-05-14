// Maria Beatriz Zanardo
// Lab 5

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

bool check(vector<int>, int, int);

int main() {
  int num, s, row;
  string tree, treestr;
  vector<int> vtree[15];	// Array of vectors to store each tree.
  vector<int> nodeCount;	// Vector to keep track of number of nodes in each tree.

  row = 0;
  s = 0;

  while (!cin.eof()){
    getline(cin, tree);
    stringstream ss(tree);
    s = 0;
    while (getline(ss,treestr, ' ')) {
      if (s == 0) {
        num = stoi(treestr);
        nodeCount.push_back(num);
        s++;
      }
      else {
        num = stoi(treestr);
        vtree[row].push_back(num);
        s++;
      }
    }
    row++;   
  }

  row--; 	// Removes last, empty line from row count.

  for (int i = 0; i < row; i++) {
    int nodeNum = nodeCount[i];
    if (nodeNum != 0) {
      check(vtree[i], nodeNum, (i+1));
    }
  }

return 0;
}

bool check (vector<int> tree, int max, int treeNum) {
  int root = tree[0];
  int num;
  int j = 0;
  int subtreesNum;
  int subtree; 	// 0 = left, 1 = right
  int min = -1;
  subtreesNum = pow(2, j);

  for (int i = 0; i != max; i++) {
    if  ( ((2*i)+1) < max ) {
      num = tree[(2*i)+1];

      if (subtreesNum > 0) {
        subtree = 0;
      }
      else {
        subtree = 1;
      }
      subtreesNum--;
    } 
    else {
      break;
    }
    
    if (subtreesNum <= min) {
      j++;
      subtreesNum = pow(2,j);
      min = -subtreesNum;  
    }

    if (num != -1) {
      if (num > tree[i]) {
        cout << "Tree " << treeNum << " is not a BST" << endl;
        return (false);
      }
      if ( (subtree == 0) && (num > root) ) {
        cout << "Tree " << treeNum << " is not a BST" << endl;
        return (false);
      }
      if ( ( subtree == 1) && (num < root) ) {
        cout << "Tree " << treeNum << " is not a BST" << endl;
        return (false);
      }
    }

    if ( ((2*i)+2) < max) {
      num = tree[(2*i)+2];
      if (subtreesNum > 0) {
        subtree = 0;
      }
      else {
        subtree = 1;
      }
      subtreesNum--;
    }
    else {
      break;
    }
    
    if (subtreesNum <= min) {
      j++;
      subtreesNum = pow(2,j);
      min = -subtreesNum;  
    }

    if (num != -1) {
      if (num <= tree[i]) {
        cout << "Tree " << treeNum << " is not a BST" << endl;
        return (false);
      }
      if ( (subtree == 0) && (num > root) ) {
        cout << "Tree " << treeNum << " is not a BST" << endl;
        return (false);
      }
      if ( ( subtree == 1) && (num < root) ) {
        cout << "Tree " << treeNum << " is not a BST" << endl;
        return (false);
      }  
    }
  }
  
  cout << "Tree " << treeNum << " is a BST" << endl;
  return (true);
}


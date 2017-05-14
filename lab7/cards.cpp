// Maria Beatriz Zanardo
// Lab 7

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct cards {
  string name;
  int rank;
  int suit;
};

bool rank_sort(const cards &a, const cards &b);	// Sorts based on rank and suit
int suit_num (string s);	// Converts suit to an integer.
int rank_convert (string r);	// Converts rank to an integer.
void display(vector<cards> a, int count);

int main() {

  string name, rank_s, suit_s, line, num;
  int rank, suit;
  int count = 0;
  vector<cards> a; 

  getline (cin, num);	// Ignores first line.

  while (1) { 
    getline (cin, line);

    if (line == "-1") {
      sort(a.begin(), a.end(), rank_sort);
      display(a, count);
      break;
    }
    if (line.length() <= 1) {	// Meaning, end of block of input.
      sort(a.begin(), a.end(), rank_sort);
      display(a, count);
      count = 0;
      a.clear();
      continue;
    }
    
    stringstream ss(line);

    getline(ss, name, ' ');
    getline(ss, rank_s, ' ');
    getline(ss, suit_s, '\n');

    rank = rank_convert(rank_s);
    suit = suit_num (suit_s);
    
    a.push_back(cards());
    a[count].name = name;
    a[count].rank = rank;
    a[count].suit = suit;
    count++;
  }

  return 0;
}

int suit_num (string s) {
  int num;
  if (s == "S") {
    num = 3;
  }
  if (s == "H") {
    num = 2;
  }
  if (s == "D") {
    num = 1;
  }
  if (s == "C") {
    num = 0;
  }
  return num;
}

int rank_convert(string r) {
  int num;
  if (r == "J") {
    num = 11;
    return num;
  }
  if (r == "Q") {
    num = 12;
    return num;
  }
  if (r == "K") {
    num = 13;
    return num;
  }
  if (r == "A") {
    num = 14;
    return num;
  }
  else {
    num = stoi(r);
    return num;
  }
}

bool rank_sort (const cards &a, const cards &b) {
  if (a.rank != b.rank) {
    return (a.rank > b.rank);
  }
  else {
    return (a.suit > b.suit);
  }
}
    
void display(vector<cards> a, int count) {
  for (int i = 0; i < (count-1); i++) {
    cout << a[i].name << ", ";
  }
  cout << a[count-1].name << endl;
}

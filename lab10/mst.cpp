#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct edge {
  int value;
  char name;
  char prev;
  bool operator < (const edge& a) const {
    return value > a.value;
  }
};

void prims(int graph [26][26]);
void push_neighbors(priority_queue<edge> &frontier, int graph [26][26], char name);

int main() {
  int graphs [10][26][26];	// It is assumed that a max of 10 graphs will be inputted at once.
  for (int g = 0; g != 10; g++) {	// Initializes graphs 
    for (int i = 0; i != 26; i++) {
      for (int j = 0; j != 26; j++) {
        graphs[g][i][j] = 0;
      }
    }
  }
  string num_s, line, nstring;
  int num, n;
  int gnum = 0;

  while (!cin.eof()) {
    getline(cin, num_s);
    if (!num_s.empty()) {
      num = stoi(num_s);
    }
    else {
      continue;
    }
    for (int i = 0; i != num; i++) {
      getline(cin, line);
      stringstream ss(line);
      for (int j = 0; j != num; j++) {
      	getline(ss, nstring, ' ');
        if (nstring.empty()) {
      	  getline(ss, nstring, ' ');
        }
      	n = stoi(nstring);
        graphs[gnum][i][j] = n;
      }
      getline(ss, nstring, '\n');
      n = stoi(nstring);
      graphs[gnum][i][num - 1] = n;
    }
    gnum++;
  }

  for (int g = 0; g != gnum; g++) { 
    prims(graphs[g]);
    if (g != gnum - 1) {
      cout << endl;
    }
  }


return 0;
}

void prims(int graph [26][26]) {
  priority_queue<edge> frontier; 
  map <char, char> marked;
  int sum = 0;
  edge start;
  start.name = 0 + 65;
  start.prev = 0 + 65;
  start.value = 0;
  frontier.push(start);
  while (!frontier.empty()) {
    edge v = frontier.top();
    frontier.pop();
    if (marked.find(v.name) != marked.end() ) {
      continue;
    }
    marked[v.name] = v.prev;
    sum = sum + v.value;
    push_neighbors(frontier, graph, v.name);
  }
  cout << sum << endl;
  multimap <char, char> ordered;
  for (auto it = marked.begin(); it != marked.end(); it++) {
    if (it->second != it->first) {
      if (it->second < it->first) {
        ordered.insert(pair <char,char> (it->second,it->first));;
      }
      else {
        ordered.insert(pair <char,char> (it->first,it->second));;

      }
    }
  }
  for (auto ito = ordered.begin(); ito != ordered.end(); ito++) {
    cout << ito->first << ito->second << endl;
  }
}

void push_neighbors(priority_queue<edge> &frontier, int graph [26][26], char name) {
  int name_i = name - 65;
  int j = 0;
  edge neighbor;

  while (graph[j][name_i] != 0) {
    if (graph[j][name_i] == 0 ) {
      break;
    }
    if (graph[j][name_i] != -1) {
      neighbor.name = j + 65;
      neighbor.prev = name;
      neighbor.value = graph[j][name_i];
      frontier.push(neighbor);
    }
    j++;
  }
}

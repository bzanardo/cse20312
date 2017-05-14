// Maria Beatriz Zanardo
// Lab 9

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <queue>

using namespace std;

typedef map <string, vector<string> > Graph;
void bft (Graph, string, string, map <string, bool>, int);

int main() {
  Graph graphs[20];	// The program takes a max of 10 graphs (other 10 store the paths to be searched for)
  string num_s, edges, src, dst;
  int num;
  int gnum = 0;
  map <string, bool> visited [20];

  while (!cin.eof()) {
    getline(cin, num_s);
    if (!num_s.empty()) {
      num = stoi(num_s);
    }
    else {
      continue;
    }
    if ( (gnum % 2 == 1) && (gnum != 1) ) {
      cout << endl;
    }
    for (int i = 0; i != num; i++) {
      getline(cin, edges);
      src = edges[0];
      dst = edges[2];
      graphs[gnum][src].push_back(dst);
      visited[gnum][src] = false;
      if (gnum % 2 == 1) {
        bft(graphs[gnum-1], src, dst, visited[gnum-1], (gnum+1)/2);
      }
    }
    gnum++;
  }

return 0;
}

void bft (Graph g, string src, string dst, map <string, bool> visited, int gnum) {
  queue <string> q;
  q.push(src);
  string src_org = src;
  bool path = false;
  while (!q.empty()) {
    src = q.front();
    q.pop();
    if (visited[src] == true) {
      continue;
    }
    visited[src] = true;
    for (auto it = g[src].begin(); it != g[src].end(); it++) {
      q.push(*it);
      if (*it == dst) {
        cout << "In Graph " << gnum << " there is a path from " << src_org << " to " << dst << endl;
        path = true;
        return;
      }
    }   
  }
  if (!path) {
    cout << "In Graph " << gnum << " there is no path from " << src_org << " to " << dst << endl;
  }
}

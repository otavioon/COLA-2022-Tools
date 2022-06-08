#include <iostream>
#include <stack>

using namespace std;

struct Vertex {
  int id;
  bool flag[8];

  Vertex(int mid) : id(mid) {
    for(int i=0; i<8; i++) {
      flag[i] = false;
    }
  }

  Vertex(const Vertex& o) {
    id = o.id;
    for(int i=0; i<8; i++) {
      flag[i] = o.flag[i];
    }
  }

  bool is_end(int N) {
    for(int i=0; i<N; i++) {
      if(flag[i] == false) {
        return false;
      }
    }
    return true;
  }
};

int g[8][8];
int main() {
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      g[i][j] = 0;
    }
  }

  int N, M;
  cin >> N >> M;

  int v, e;
  for(int i=0; i<M; i++) {
    cin >> v >> e;
    v--;
    e--;
    g[v][e] = g[e][v] = 1;
  }

  stack<Vertex> s;
  s.push(Vertex(0));
  int count = 0;
  while(!s.empty()) {
    Vertex targ = s.top();
    s.pop();
    targ.flag[targ.id] = true;

    if(targ.is_end(N)) {
      count++;
    }
    else {
      for(int i=0; i<N; i++) {
        if(g[targ.id][i] == 1 && targ.flag[i] == false) {
          Vertex tmp(targ);
          tmp.id = i;
          s.push(tmp);
        }
      }
    }
  }

  cout << count << endl;
  return 0;
}
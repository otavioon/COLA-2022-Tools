#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

int main(){

  int N, Q; cin >> N >> Q;

  bool graph[N][N];
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      graph[i][j] = false;
    }
  }

  for (int i = 0; i < N - 1; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    graph[a][b] = true;
  }

  int score[N];
  for (int i = 0; i < N; i++){
    score[i] = 0;
  }

  for (int i = 0; i < Q; i++){
    int p, x; cin >> p >> x; p--;

    bool check[N];
    for (int j = 0; j < N; j++) check[j] = false;
    
    queue <int> que;
    que.push(p); check[p] = true;

    while (!que.empty()){
      int edge = que.front(); que.pop();

      for (int j = 0; j < N; j++){
        if (graph[edge][j] == true && check[j] == false){
          que.push(j);
          check[j] = true;
        }
      }
    }
    
    for (int j = 0; j < N; j++){
      if (check[j] == true){
        score[j] += x;
      }
    }
  }
  
  for (int i = 0; i < N; i++){
    cout << score[i];
    if (i != N - 1) cout << " ";
    else cout << endl;
  }
  
  return 0;
}

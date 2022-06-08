#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, ans = 0;
  cin >> N;
  vector<string> blue(N);
  for(int i;i < N;i++){
    cin >> blue.at(i);
  }
  
  cin >> M;
  vector<string> red(M);
  for(int i;i < M;i++){
    cin >> red.at(i);
  }
  
  vector<int> cul(M + N);

  for(int i;i < N;i++){
    //*************
    for(int j;j < N;j++){
      if (blue.at(i) == blue.at(j)){
        cul.at(i)++;
      }
    }
   
    
    for(int j;j < M;j++){
      if (blue.at(i) == red.at(j)){
        cul.at(i)--;
      }
    }
    //***********
  }
  
  for(int i;i < M;i++){
    for(int j;j < N;j++){
      if (red.at(i) == blue.at(j)){
        cul.at(i + N)++;
      }
    }
    for(int j;j < M;j++){
      if (red.at(i) == red.at(j)){
        cul.at(i + N)--;
      }
    }
  }
  
  for(int i;i < M+N;i++){
    if (ans < cul.at(i)){
      ans = cul.at(i);
    }
  }

  cout << ans << endl;
}
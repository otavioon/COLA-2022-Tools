#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> blue(N);
  for (int i=0; i<N; i++){
    cin >> blue.at(i);
  }
  int M;
  cin >> M;
  vector<string> red(M);
  for (int i=0; i<M; i++){
    cin >> red.at(i);
  }
  int money =0;
  int n=0;
  for (int j=0; j<N; j++){
    int count =0;
    blue.at(0) = blue.at(n);
    for(int m=0; m<N; m++){
      if (blue.at(0) == blue.at(m)){
        count++;
        continue;
      }
      else
        continue;
    }
    for (int l=0; l<M; l++){
      if (blue.at(0) == red.at(l)){
        count--;
        continue;
      }
      else
        continue;
    }
    n++;
    if ((count > money)&&(n ==1)){
      money = count;
      continue;
    }
    else if((count > money)&&(n != 1)){
      money = count -1;
      continue;
    }
    else
      continue;
  }
  cout << money << endl;
}
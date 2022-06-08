#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string s[N];
  for(int i=0;i<N;i++){
    cin >> s[i];
  }
  int M;
  cin >> M;
  string t[M];
  for(int i=0;i<M;i++){
    cin >> t[i];
  }
  vector<int> score(N+M,0);
  string str[N+M];
  int k=0;
  bool flag=false;
  for(int i=0;i<N;i++){
    str[k]=s[i];
    if(k==0){
      score.at(k)++;
      k++;
      continue;
    }
    for(int j=0;j<k+1;j++){
      if(j==k){
        score.at(j)++;
        k++;
        break;
      }
      if(str[j]==str[k]){
        score.at(j)++;
        break;
      }
    }
  }
  for(int i=0;i<M;i++){
    str[k]=t[i];
    if(k==0){
      score.at(k)--;
      k--;
      continue;
    }
    for(int j=0;j<k+1;j++){
      if(j==k){
        score.at(j)--;
        k--;
        break;
      }
      if(str[j]==str[k]){
        score.at(j)--;
        break;
      }
    }
  }
  int tmp=-1000;
  for(int i=0;i<k+1;i++){
    if(tmp<score.at(i)){
      tmp=score.at(i);
    }
  }
  cout << tmp << endl;
}

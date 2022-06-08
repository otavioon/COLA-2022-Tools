#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  int max=-100;
  cin >> N;
  vector<string> s(N);
  for(int i=0;i<N;i++){
    cin >> s.at(i);
  }
  cin >> M;
  vector<string> t(M);
  for(int i=0;i<M;i++){
    cin >> t.at(i);
  }
  vector<int> totalscore(N+M,0);
  for(int i=0;i<M+N;i++){
    for(int j=0;j<M+N;j++){
      if(i<N && j<N){
        if(s.at(i)==s.at(j))totalscore.at(i)++;
      }
      else if(i<N && j>=N){
        if(s.at(i)==t.at(j-N))totalscore.at(i)--;
      }
      else if(i>=N && j<N){
        if(t.at(i-N)==s.at(j))totalscore.at(i)++;
      }
      else{
        if(t.at(i-N)==t.at(j-N))totalscore.at(i)--;
      }
    }
  }
  for(int i=0;i<M+N;i++){
    if(totalscore.at(i)>=max)max=totalscore.at(i);
  }
  cout << max << endl;
}

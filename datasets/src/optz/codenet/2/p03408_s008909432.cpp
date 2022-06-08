#include <bits/stdc++.h>
using namespace std;

int main(){

  int N;
  cin >> N;
  string S;
  map<string,int> card;
  for(int i=0; i<N; i++){
    cin >> S;
    card[S]++;
  }

  int M;
  cin >> M;
  for(int i=0; i<M; i++){
    cin >> S;
    card[S]--;
  }
  
  int max_card = 0;
  for(auto x:card){
    if(max_card < x.second){
      max_card = x.second;
    }
  }

  cout << max_card << endl;
  
}
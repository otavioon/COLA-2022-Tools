#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0)

bool isValidNumber(int N,set<char> &D){
  string num = to_string(N);
  for(int i=0; i<num.size(); ++i)
    if(D.count(num[i])==1)
      return false;
  return true;
}

int main(){
  int N, K, i;
  set<char> D;
  char c;
  cin>>N>>K;
  for(i=0; i<K; i++){
    cin>>c;
    D.insert(c);
  }
  while(!isValidNumber(N,D)){
    N++;
  }
  cout<<N<<endl;
  
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<string>s(N);
  for(int i=0;i<N;i++){
    cin>>s.at(i);
  }
  int M;
  cin>>M;
  vector<string>t(M);
  for(int i=0;i<M;i++){
    cin>>t.at(i);
  }
  int sum=0;
  for(int i=0;i<N;i++){
    int plus=0;
    int minus=0;
    for(int j=0;j<N;j++){
      if(s.at(j)==s.at(i)){
        plus=plus+1;
      }
      else{
      }
    }
    for(int j=0;j<M;j++){
      if(t.at(j)==s.at(i)){
        minus=minus+1;
      }
      else{
      }
    }
    sum=max(sum,plus-minus);
  }
  cout<<sum<<endl;
}
  
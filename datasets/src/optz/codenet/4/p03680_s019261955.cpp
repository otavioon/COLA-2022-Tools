#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> a(N+1);
  vector<bool> flg(N+1);
  for(int i=1;i<=N;i++){
    cin>>a.at(i);
  }
  
  int next=a.at(1);
  flg.at(1)=true;
  int count=1;
  while(1){
    if(next==2){
      break;
    }
    if(flg.at(next)==true){
      count=-1;
      break;
    }
    flg.at(next)=true;
    next=a.at(next);
    count++;
  }
  cout<<count<<endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,K,X;
  cin>>N>>K;
  vector<int> vec(20);
  rep(i,K){cin >> X;
           vec.at(X)=1;
           vec.at(X+10)=1;}
  
  vector<int> Ans(5);
  Ans.at(4)=N%10;
  Ans.at(3)=N%100/10;
  Ans.at(2)=N%1000/100;
  Ans.at(1)=N%10000/1000;
  Ans.at(0)=N/10000;
  
  for (int i=4;i>0;i--){
  while(vec.at(Ans.at(i))>0){Ans.at(i)++;}
  Ans.at(i-1)+=Ans.at(i)/10;}
  
  if(Ans.at(0)>0){while(vec.at(Ans.at(0))>0){Ans.at(0)++;}cout<<Ans.at(0)%10;}
  cout<<Ans.at(1)%10<<Ans.at(2)%10<<Ans.at(3)%10<<Ans.at(4)%10<<endl;
}
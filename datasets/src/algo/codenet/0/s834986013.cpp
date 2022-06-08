#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
#include<bitset>
#include<queue>
#define ll long long
#define itn int
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007
using namespace std;

int main(){
  ll K,L=0,T=0,cnt=1;
  string S;
  cin>>S>>K;
  bool CAN=true,TUG=true;
  ll e=0,q=0;
  
  for(int i=0; i<S.size(); ++i){
      if(i==S.size()-1){
        if(CAN){
          q=cnt;
          CAN=false;
        }
        L+=cnt/2;
        cnt=1;
      }
    
      else if(S.at(i)!=S.at(i+1)){
        if(CAN){
          e=cnt;
          CAN=false;
        }
        TUG=false;
        L+=cnt/2;
        cnt=1;
      }
      else if(S.at(i)==S.at(i+1)){
        cnt++;
      }
  }
  
  if(S.at(0)==S.at(S.size()-1)){
    if(e%2==1 && q%2==1) T++;
  }
  
  if(TUG){
    cout<<(S.size()*K)/2<<endl;
    return 0;
  }
  
  cout<<L*K+T*(K-1)<<endl;
}
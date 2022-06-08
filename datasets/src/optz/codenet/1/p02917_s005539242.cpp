#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
#include<bitset>
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,0,n)
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007
using namespace std;

int main(){
  int N,ans=0;
  cin>>N;
  int A[N-1];
  REP(i,N-1) cin>>A[i];
  
  if(N>=3){
  for(int i=0; i<N-2; ++i) ans+=min(A[i],A[i+1]);
  ans+=A[0];
  ans+=A[N-2];
  }
  
  else if(N==2) ans=A[0]+A[1]+min(A[0],A[1]);
  
  cout<<ans<<endl;
}
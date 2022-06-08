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
  int N,Q;
  cin>>N>>Q;
  ll A[N],B[N],C[N+1],P[Q],X[Q];
  REP(i,N-1) cin>>A[i]>>B[i];
  REP(i,Q) cin>>P[i]>>X[i];
  
  REP(i,N+1) C[i]=0;
  REP(i,Q) C[P[i]]+=X[i];
  
  int L[N+1]; //L[i]は頂点iの親
  REP(i,N+1) L[i]=i;
  REP(i,N-1) L[B[i]]=A[i];
  
  FOR(i,2,N+1) C[i]+=C[L[i]];
  
  FOR(i,1,N+1) cout<<C[i]<<" ";
  cout<<endl;
}

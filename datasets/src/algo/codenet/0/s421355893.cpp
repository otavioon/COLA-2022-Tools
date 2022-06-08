#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
signed main(){
  string S; cin>>S;
  int K; cin>>K;
  int N=S.size();
  int ans=0;
  bool flag=0,F=1;
  if(S[0]==S[N-1]){
    flag=1;
    if(S[0]==S[1]){
      S[0]='?';
      F=0;
    }
    else S[N-1]='?';
  }
  if(F){
    REP(i,2,N){
      if(S[N-i]==S[N-i+1]){
        S[N-i]='?';
        ans++;
      }
    }
  }
  else{
    rep(i,0,N-1){
      if(S[i]==S[i+1]){
        ans++;
        S[i+1]='?';
      }
    }
  }
  ans*=K;
  if(flag) ans+=K-1;
  cout<<ans<<endl;
  }


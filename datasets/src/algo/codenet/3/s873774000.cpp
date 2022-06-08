#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(long long i=0;i<(n);++i)
#define Fr(i,n) for(long long i=1;i<=(n);++i)
#define ifr(i,n) for(long long i=(n)-1;i>=0;--i)
#define iFr(i,n) for(long long i=(n);i>0;--i)
using Graph = vector<vector<int>>;

 
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q,p,ans,b,a,c;
  cin>>n;
  ans=0;
  a=0;
  c=0;
  ll arra[n];
  ll arrb[n];
  ll arrc[n];
  fr(i,n){
      ll r;
      cin>>r;
      arra[i]=r;
  }
  fr(i,n){
      ll r;
      cin>>r;
      arrb[i]=r;
  }
  fr(i,n){
      ll r;
      cin>>r;
      arrc[i]=r;
  }
  sort(arra,arra+n);
  sort(arrb,arrb+n);
  sort(arrc,arrc+n);
  fr(i,n){
      while(a!=n-1 and arra[a+1]<arrb[i]) ++a;
      while(c!=n and arrc[c]<=arrb[i]) ++c;
      ans+=(a+1)*(n-c);
  }
  cout<<ans;
}
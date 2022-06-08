#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <algorithm> 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<endl
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define mp make_pair
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define sz(x) (ll)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pll = pair<ll, ll>;
using vc = vector<char>;
using vvc = vector<vc>;
template<class T> inline bool chmax(T& a, T b) {
 if (a < b) { a = b; return true; } return false; 
 }
template<class T> inline bool chmin(T& a, T b) {
 if (a > b) { a = b; return true; } return false; 
 }
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};

bool ch(ll cu,ll n,ll a,ll b,vll h){
  ll ccu=0;
  rep(i,n){
    if(h[i]>cu*b){
      ll no=h[i]-cu*b;
      ccu+=(no-a+b-1)/(a-b);
    }
  }
  if(ccu>cu) return false;
  else return true;
}
int main(){
  ll n,a,b;
cin>>n>>a>>b;
  vll h(n);
  rep(i,n) cin>>h[i];
  ll r=1e9;
  ll l=-1;
  while(l+1<r){
    ll mid=(l+r)/2;
    if(!ch(mid,n,a,b,h)){
      l=mid;
    }
    else r=mid;
  }
  COUT(r);
}
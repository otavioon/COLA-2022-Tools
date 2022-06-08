#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#include <bitset>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define pb push_back
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}

ll N,A,B;
vector<ll> H;

bool isok(ll x){
  // code here
  ll add = 0;
  ll dall = B*x;
  ll pls = A-B;
  rep(i,N){
    ll hp = H[i]-dall;
    if(hp>0) add += (hp+pls-1)/pls;
  }

  if(add<=x) return true;
  else return false;
}
ll binsch(){
  // set value
  ll ng = 0; ll ok = 1e9+10;
  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    if(isok(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main(){
  cin >> N >> A >> B;
  H.resize(N); rep(i,N) cin >> H[i];
  cout << binsch() << endl;
  return 0;
}

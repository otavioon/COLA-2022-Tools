// Created by Sharat Sachin
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)

using namespace std;
using ll = long long;

set<char> v;

bool check(int n){
  string s = std::to_string(n);
  for(char x: s){
    if(v.find(x)!=v.end()) return true;
  } 
  return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, xx;
    cin>>xx>>n;
    rep(i,n) {
      char s;
      cin>>s;
      v.insert(s);
    }
    while(check(xx)) xx++;
    cout<<xx;
    return 0;
}
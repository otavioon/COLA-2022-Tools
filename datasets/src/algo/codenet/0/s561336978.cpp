// template version 1.12
using namespace std;
#include <iostream>
#include <bits/stdc++.h>

// varibable settings
#define infile "../test/sample-1.in"
#define int long long //{{{
const int INF=1e18;
const int MOD=1e9+7; //}}}

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define ceil(a,b) ((a)+(b)-1)/(b)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
  #include "lib/dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
//}}}

int solve(){
  string s;cin>>s;
  int k;cin>>k;

  int n = sz(s);
  if (n==1){
    cout << k/2 << endl;
    return 0;
  }

  int cnt1 = 0;
  bool flag1 = false;
  rep(i, 1, n){
    if (s[i]==s[i-1]){
      if (i==n-1){
        flag1 = true;
      }
      cnt1++;
      i++;
    }
  }
  int cnt2 = 1;
  bool flag2 = false;
  rep(i, 2, n){
    if (s[i]==s[i-1]){
      if (i==n-1){
        flag2 = true;
      }
      cnt2++;
      i++;
    }
  }
  dump(cnt1, flag1);
  dump(cnt2, flag2);

  if (s[0]==s[n-1]){
    if (flag1){
      cout << cnt1*k << endl;
      return 0;
    }
    else{
      if (flag2){
        //c1->c2->c1->c2
        dump(cnt1, (k+2-1)/2, cnt2, k/2);
        int ans = 0;
        ans += cnt1 * ((k+2-1)/2);
        ans += cnt2 * (k/2);
        cout <<  ans  << endl;
      }
      else{
        //c1->c2->c2->c2
        dump("hello");
        cout << cnt1 + cnt2*(k-1) << endl;
        return 0;
      }
    }
  }
  else{
    dump(cnt1);
    cout << cnt1*k << endl;
    return 0;
  }

  return 0;
}

signed main() { //{{{
#ifdef INPUT_FROM_FILE
  std::ifstream in(infile);
  std::cin.rdbuf(in.rdbuf());
#endif
  solve();
  return 0;
} //}}}

// ------------------------------------
// Date:2018/ 3/ 7
// Problem:ABC 077 Rotation a.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

static const int MOD = 1000000007;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  char c[2][3];
  REP(hi, 2) {
    REP(wi, 3) {
      cin >> c[hi][wi];
    }
  }

  bool ok = true;
  REP(hi, 2) {
    REP(wi, 3) {
      if (c[hi][wi] != c[1 - hi][2 - wi]) ok = false;
    }
  }

  cout << (ok ? "YES" : "NO" ) << endl;
  
  return 0;
}


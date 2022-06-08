
#include <cstdio>
#include <algorithm>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;

int as[100000+10];
int bs[100000+10];
int cs[100000+10];

ll bbs[100000+10];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &as[i]);
  }
  REP(i, n) {
    scanf("%d", &bs[i]);
  }
  REP(i, n) {
    scanf("%d", &cs[i]);
  }

  sort(as, as + n);
  sort(bs, bs + n);
  sort(cs, cs + n);

  {
    int ia = 0;
    REP(ib, n) {
      int b = bs[ib];
      while(ia < n && as[ia] < b) {
        ++ia;
      }
      bbs[ib] = (ib == 0 ? 0 : bbs[ib-1]) + ia;
      // cerr << ">> " << bbs[ib] << endl;
    }
  }

  ll res = 0;
  {
    int ib = 0;
    REP(ic, n) {
      int c = cs[ic];
      while(ib < n && bs[ib] < c) {
        ib++;
      }
      res += ib-1 < 0 ? 0 : bbs[ib-1];
      // cerr << "> " << res << endl;
    }
  }

  printf("%lld\n", res);
  
  return 0;
}

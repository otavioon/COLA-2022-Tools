#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int main (void) {
  int s = 0;
  REP(i, 3) REP(j, 3) {
    int in;
    cin >> in;
    s += in;
  }
  cout << (s % 3 == 0 ? "Yes" : "No") << endl;
  return 0;
}

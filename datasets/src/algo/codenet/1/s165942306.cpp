#include <bits/stdc++.h>
#define FOR(i, a, n) for(int (i) = (int)(a); (i) < (int)(n); ++(i))
#define FORe(i, a, n) for(int (i) = (int)(a); (i) <= (int)(n); ++(i))
#define rFOR(i, a, n) for(int (i) = (int)(n)-1; (i) >= (int)(a); --(i))
#define REP(i, n) FOR((i), 0, (n))
#define REPe(i, n) FORe((i), 0, (n))
#define rREP(i, n) rFOR((i), 0, (n))
#define rep(i, n) FOR((i), 0, (n))
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int c[3][3];

int main() {
  REP(i, 3) REP(j, 3) cin >> c[i][j];
  if(c[0][0]+c[1][1]+c[2][2]==c[0][1]+c[1][2]+c[2][0]&&c[0][1]+c[1][2]+c[2][0]==c[0][2]+c[1][0]+c[2][1]) {
    cout << "Yes" << endl;
  }else cout << "No" << endl;

  return 0;
}
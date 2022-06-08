#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> pint;
template <class T> inline void chmax(T &a, const T b) { a = max(a, b); }
template <class T> inline void chmin(T &a, const T b) { a = min(a, b); }
template <class T> void pp(T v, int n) { REP(i,n) cout<<v[i]<< ' '; cout << endl; }

void inline TorF(bool tf, const string &trueMessage, const string &falseMessage) { 
  cout << (tf ? trueMessage : falseMessage) << endl;
}
void inline YESNO(bool tf) { TorF(tf, "YES", "NO"); }
void inline YesNo(bool tf) { TorF(tf, "Yes", "No"); }

int main() {
  int N; cin>>N;
  vector<int> L(1000+1, 0);
  REP(i,N) {
    int a; cin>>a;
    L[a]++;
  }
  ll ans = 0;
  //  pp(L, 10);
  for(int i = 1; i <= 1000; i++) {
    for(int j = i; j <= 1000; j++) {
      for(int k = j; k <= 1000; k++) {
	if(k >= i + j) break;
	if(i >= j + k) continue;
	if(j >= i + k) continue;
	int a = L[i];
	int b = (i == j ? a-1 : L[j]);
	int c = (j == k ? b-1 : L[k]);
	ll tmp = a * b *  c;
	ans += tmp;
      }
    }
  }
  cout << ans << endl;

  return 0;
}

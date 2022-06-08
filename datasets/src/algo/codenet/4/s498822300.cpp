#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
#include<climits>
#include<queue>
#include<utility>
#include<functional>
#include<memory>
using namespace std;
#define fi first
#define se second
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;

int N, K;
set< int > d;

int a[9], tot, ret, len;

void dfs(int pos, int num, bool unlim) {
  if (pos > len) {
    if (num >= N) {
      ret = min(ret, num);
      return;
    }
  }

  for (int i = (pos == 1); i <= 9; ++i) {
    if (d.find(i) != d.end()) {
      continue;
    }
    dfs(pos + 1, num * 10 + i, unlim | (i < a[pos]));
  }

}

void solve(int x) {
  // memset(f, 0x3f, sizeof(f));

  len = 0;
  int nn = N;
  while (nn) {
    nn /= 10;
    ++len;
  }

  tot = 0;
  while (x) {
    a[++tot] = x % 10;
    x /= 10;  
  }
  reverse(a + 1, a + tot + 1);

  ret = INF;
  dfs(1, 0, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N >> K;
  for (int k = 0; k < K; ++k) {
    int x; 
    cin >> x;
    d.insert(x);
  }
  
  solve(99999);
  cout << ret << endl;

  return 0;
}
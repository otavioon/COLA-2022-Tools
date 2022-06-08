#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>

using namespace std;
typedef long long unsigned int ll;
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF (1e12)
#define PI (acos(-1))

#define amari(x) ((x) % 1000000007)

#define fillInt(xs, x)        \
  for (int i = 0; i < (x); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%ld", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < (x); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvdi(xs) sort(xs.begin(), xs.end(), std::greater<int>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)

#define rep(i,n) for(int i=0; i<(n); i++)
#define isValidPoint(x, y, mx, my) x >= 0 && x  < mx && y >= 0 && y < my

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int cnts[1000000000] = {};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  long n;
  cin >> n;
  vector<long> a(n);
  fillLong(a, n);
  sortv(a);

  long m = 1;
  
  while (m <= 1000000000*2) {
    m*=2;
  }

  rep(i, n) {
    cnts[a[i]]++;
  }

  long cnt = 0;
  for (long i = n-1; i > 0; i--) {
    if (cnts[a[i]] == 0) continue;
    for (long j = m; j > 1; j = j/2) {
      if (bs(a, j-a[i]) && ((j-a[i] == a[i] && cnts[j-a[i]]>1) || (j-a[i] != a[i] && cnts[j-a[i]]>0))) {
        cnt++;
        cnts[a[i]]--;
        cnts[j-a[i]]--;
        break;
      }
    }
  }

  cout << cnt << endl;

  return 0;
}

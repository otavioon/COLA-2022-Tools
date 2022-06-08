#include <stdio.h>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void) {
  ll i, j, n, ans = 0, now = 0;
  scanf("%lld", &n);
  ll a[3][n], cnt[n];
  for(i = 0; i < 3; ++i) for(j = 0; j < n; ++j) scanf("%lld", &a[i][j]);
  for(i = 0; i < 3; ++i) sort(a[i], a[i] + n);
  for(i = 0; i < n; ++i) {
    while(now != n && a[0][now] < a[1][i]) now++;
    cnt[i] = now;
    if(i) cnt[i] += cnt[i - 1];
  }
  now = 0;
  for(i = 0; i < n; ++i) {
    while(now != n && a[1][now] < a[2][i]) now++;
    if(now) now--, ans += cnt[now];
  }
  printf("%lld", ans);
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
int n;
typedef long long ll;
ll a[100001];
ll b[100001];
ll c[100001];
int main() {
  cin >> n;

  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n; i++) cin >> c[i];
  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);

  ll ans = 0;

  int i = 0, j = 0, k = 0;

  while(i < n) {
    j = 0;
    while(b[j] <= a[i]) j++;
    k = 0;
    while(j < n) {
    while(c[k] <= b[j]) k++;
    ans += n - k;
    j++;
    }
    i++;
  }

  cout << ans << endl;
}

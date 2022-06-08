#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n, k; cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  auto f = [&](double x){
    int cnt = 0;
    for(int i = 0; i < n; i++){
      if(a[i] % (int)(x+0.5) == 0) cnt += a[i] / (int)(x+0.5) - 1;
      else cnt += a[i] / (int)(x+0.5);
    }
    return cnt;
  };
  
  int ans = INF;
  double left = 1, right = 1e9;
  while(right - left > 1e-2){
    double mid = (left + right) / 2;
    int cnt = f(mid);
    (cnt <= k ? right : left) = mid;
    if(cnt <= k) ans = min(ans, (int)(mid+0.5));
  }
  if(ans == INF) ans = 1;
  cout << ans << endl;

  return 0;
}
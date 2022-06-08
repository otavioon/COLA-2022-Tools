#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<double> a;

bool c(double x){
  int cnt = 0;
  for(int i=0; i<n; i++){
    cnt += (int)a[i]/x;
    if((int)(a[i]/x)*x == a[i])  cnt--;
  }
  return cnt <= k;
}

int main(){
  cin >> n >> k;
  a.resize(n);
  for(int i=0; i<n; i++)  cin >> a[i];

  double s = 0, t = 1e9+2;
  for(int i=0; i<1000; i++){
    double mid = (s + t) / 2;
    if(c(mid))  t = mid;
    else  s = mid;
  }

  int ans = (int)t + 1;
  if(t - (double)(int)(t))  ans--;

  cout << ans << endl;
  
  return 0;
}

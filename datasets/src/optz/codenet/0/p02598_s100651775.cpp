#include <iostream>
#include <cmath>
using namespace std;
int n, k;
int a[200001]; // 累積和を格納する

bool canCut(double x) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    count += ceil(a[i] / x) - 1;
    if (count > k) return false;
  }
  if (count <= k) return true;
  else return false;
}

void solve() {
  // 二分探索
  double ub = -1, lb = 10e9 + 1;
  while (lb - ub > 0.01) {
    double mid = (ub + lb) / 2;
    mid *= 100;
    mid = round(mid);
    mid /= 100;
    if (canCut(mid)) {
      lb = mid;
    } else {
      ub = mid;
    } 
  }
  printf("%.0lf", ceil(lb));
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  solve();
}
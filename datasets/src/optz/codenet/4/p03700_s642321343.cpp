#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin>>n>>a>>b;
  int h[n];
  for (int i=0; i<n; i++) cin>>h[i];
  long long sum = 0;
  sort(h, h + n);
  for (int i=0; i<n; i++) sum += h[i];

  int begin = 1;
  int end = (h[n-1] - 1) / b + 1;
  set<int> ans;
  while (begin < end - 1) {
    int k = begin + (end - begin) / 2;
    long long cnt = 0;
    bool ok = true;
    for (int i=0; i<n; i++) {
      if (h[i] - b * k <= 0) {
        continue;
      }
      cnt += (h[i] - b * k - 1) / (a - b) + 1;
      if (cnt > k) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans.insert(k);
      end = k;
    } else {
      begin = k;
    }
  }
  cout<<*ans.begin()<<endl;
}
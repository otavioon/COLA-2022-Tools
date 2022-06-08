#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];

  sort(a, a + n);

  set<int> used;
  for (int i=n-1; i>=0; i--) {
    if (used.find(i) != used.end()) {
      continue;
    }
    for (int j=31; j>=0; j--) {
      long b = pow(2, j) - a[i];
      auto it = lower_bound(a, a + i, b);
      if (it != a + i && (*it) == b) {
        used.insert(i);
        used.insert(it - a);
        break;
      }
    }
  }
  cout<<used.size()/2<<endl;
}
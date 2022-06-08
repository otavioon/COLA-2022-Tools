#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  long a[n];
  for (int i=0; i<n; i++) cin>>a[i];

  sort(a, a + n);

  set<int> used;
  for (int i=32; i>=0; i--) {
    long b = pow(2, i);
    for (int j=n-1; j>=0; j--) {
      if (used.find(j) != used.end()) {
        continue;
      }
      long c = b - a[j];
      if (c < 1) {
        break;
      }
      auto it = lower_bound(a, a + j, c);
      if (it == a + j) {
        continue;
      }
      while (it != a + j && *it == c) {
        if (used.find(j) == used.end() && used.find(it-a) == used.end()) {
          used.insert(j);
          used.insert(it - a);
          break;
        }
        ++it;
      }
    }
  }
  cout<<used.size()/2<<endl;
}
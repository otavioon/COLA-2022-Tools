#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,d;
  cin >> n >> d;
  int num=0, ans=0;
  for (int i; i<n; i++) {
    num+=2*d+1;
    ans++;
    if (num>=n) {
      break;
    }
  }
  cout << ans <<endl;
}

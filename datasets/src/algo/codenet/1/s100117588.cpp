#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    int a;
    cin >> a;
    sum += a;
  }

  if (sum%3==0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
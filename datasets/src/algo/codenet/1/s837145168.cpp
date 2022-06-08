#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int sum = 0, ab = 0;
  rep(i,3)rep(j,3) {
    int c;
    cin >> c;
    sum += c;
    if (i == j) ab += c;
  }
  if(sum == 3 * ab) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
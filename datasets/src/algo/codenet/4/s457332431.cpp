#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  string n;
  int k;
  cin >> n >> k;
  set<char> d;
  rep(i, k) {
    char tmp;
    cin >> tmp;
    d.insert(tmp);
  }
  int p = stoi(n);

  int l = n.length();
  for (int i = l - 1; i >= 0; i--) {
    while (true) {
      if (d.count(n[i]) == 0) break;
      n[i]++;
      if (n[i] > '9') {
        n[i] = *d.begin();
        if (i != 0) {
          n[i - 1]++;
        }
      }
    }
  }
  int c = stoi(n);
  if (c < p) {
    n = *d.begin() + n;
  }
  cout << n << endl;
}

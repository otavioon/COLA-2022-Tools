#include <bits/stdc++.h>

using namespace std;

int N;
multiset<long long> A;
int R;

int buddy(int x) {
  int p = 1;
  while(p <= x) p *= 2;
  return p - x;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; ++i) {
    long long a; cin >> a; A.insert(a);
  }
  while(!A.empty()) {
    auto it = A.end(); --it;
    int x = *it; A.erase(it);
    int y = buddy(x);
    it = A.find(y);
    if(it != A.end()) {
      A.erase(it);
      ++R;
    }
  }
  cout << R << endl;
  return 0;
}

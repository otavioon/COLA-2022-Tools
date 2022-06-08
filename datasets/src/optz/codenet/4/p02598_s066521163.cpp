#include<iostream>
#include<set>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
  auto log_cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
    long x = (long)(a.first + a.second - 1) * b.second;
    long y = (long)(b.first + b.second - 1) * a.second;
    if (x == y) return a.second < b.second;
    return x > y;
  };
  set<pair<int, int>, decltype(log_cmp)> S(log_cmp);
  for (int i = 0; i < N; i++) S.insert(make_pair(A[i], 1));
  for (int i = 0; i < K; i++) {
    auto it = S.begin();
    auto new_pair = make_pair(it->first, it->second + 1);
    S.erase(it);
    S.insert(new_pair);
  }
  int l = S.begin()->first;
  int m = S.begin()->second;
  cout << (l+m-1)/m << endl;
}
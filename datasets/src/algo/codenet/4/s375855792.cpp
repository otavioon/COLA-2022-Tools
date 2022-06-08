#include <iostream>
#include <climits>
#include <set>

using namespace std;

int hoge(set<int>&vec, int n, int cnt=0, int vsum=0) {
  if (cnt == 5)
    return (n <= vsum) ? vsum : INT_MAX;

  int ret = hoge(vec, n, cnt+1, vsum);
  for (auto &v : vec)
    ret = min(ret, hoge(vec, n, cnt+1, vsum*10+v));
  return ret;
}

int main() {
  int n, k;
  cin >> n >> k;
  set<int> vec;
  for (int i = 0; i < 10; ++i)
    vec.insert(i);
  for (int i = 0; i < k; ++i) {
    int d;
    cin >> d;
    vec.erase(d);
  }
  cout << hoge(vec, n) << endl;
}

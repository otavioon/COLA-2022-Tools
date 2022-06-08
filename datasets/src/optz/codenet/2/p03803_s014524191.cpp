#include <bits/stdc++.h>
#define sz(arr) (int)arr.size()

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  map<int, int> mp;
  for (int i = 2; i <= 13; ++i) mp[i] = i;
  mp[1] = 14;

  puts(mp[a] > mp[b] ? "Alice" : mp[a] < mp[b] ? "Bob" : "Draw");

  return 0;
}
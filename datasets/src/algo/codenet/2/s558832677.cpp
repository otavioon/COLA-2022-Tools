#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
  int N;
  cin >> N;
  multiset<int> ms;

  rep(i, N)
  {
    int a;
    cin >> a;
    ms.insert(a);
  }

  int ans = 0;

  while (!ms.empty())
  {
    auto it = --ms.end();
    int v = *it;
    ms.erase(it);

    int b = 1;
    while (b <= v)
      b *= 2;

    auto jt = ms.find(b - v);
    if (jt != ms.end())
    {
      ans++;
      ms.erase(jt);
    }
  }

  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;

int main()
{
  int64_t N, K, d;
  cin >> N >> K;
  vector<bool> ok(10, true);
  for (int i = 0; i < K; i++)
  {
    cin >> d;
    ok.at(d) = false;
  }
  for (int64_t i = N; i < MAXN * 100; i++)
  {
    int64_t n = i;
    bool flg = true;
    while (n > 0)
    {
      if (!ok.at(n % 10))
      {
        flg = false;
      }
      n /= 10;
    }
    if (flg)
    {
      cout << i << endl;
      return 0;
    }
  }
}
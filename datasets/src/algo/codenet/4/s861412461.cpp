#include <bits/stdc++.h>
using namespace std;
vector<bool> Cost(10001, true);

int main()
{
  int64_t N, K, k;
  cin >> N >> K;
  for (int i = 0; i < K; i++)
  {
    cin >> k;
    Cost.at(k) = false;
    if (k == 0 || k == 1)
      Cost.at(10000) = false;
    for (int n = 10; n < 10000; n++)
    {
      if (n >= 1000 && n / 1000 == k)
        Cost.at(n) = false;
      else if (n >= 100 & (n % 1000) / 100 == k)
        Cost.at(n) = false;
      else if ((n % 100) / 10 == k)
        Cost.at(n) = false;
      else if ((n % 10) == k)
        Cost.at(n) = false;
    }
  }
  for (int i = N; i <= 10000; i++)
  {
    if (Cost.at(i))
    {
      cout << i << endl;
      return 0;
    }
  }
}

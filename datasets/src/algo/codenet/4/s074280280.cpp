#include <bits/stdc++.h>
using namespace std;
vector<bool> Cost(100000, true);

int main()
{
  int64_t N, K, k;
  cin >> N >> K;
  for (int i = 0; i < K; i++)
  {
    cin >> k;
    for (int n = 0; n < 100000; n++)
    {
      if (n >= 10000 && n / 10000 == k)
        Cost.at(n) = false;
      else if (n >= 1000 && (n % 10000) / 1000 == k)
        Cost.at(n) = false;
      else if (n >= 100 & (n % 1000) / 100 == k)
        Cost.at(n) = false;
      else if (n >= 10 && (n % 100) / 10 == k)
        Cost.at(n) = false;
      else if (n % 10 == k)
        Cost.at(n) = false;
    }
  }
  for (int i = N; i < 100000; i++)
  {
    if (Cost.at(i))
    {
      cout << i << endl;
      return 0;
    }
  }
}

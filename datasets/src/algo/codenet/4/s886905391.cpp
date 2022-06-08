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
    for (int j = k * 10; j <= k * 10 + 9; j++)
      Cost.at(j) = false;
    for (int j = k * 100; j <= k * 100 + 99; j++)
      Cost.at(j) = false;
    for (int j = k * 1000; j <= k * 1000 + 999; j++)
      Cost.at(j) = false;
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

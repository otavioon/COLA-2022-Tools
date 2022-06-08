#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, ans = 0, on = 1;
  cin >> N;
  vector<int> A(N + 1);
  vector<bool> Visited(N + 1, 0);
  for (int i = 1; i <= N; i++)
  {
    cin >> A.at(i);
  }
  while (true)
  {
    ans++;
    int nxt = A.at(on);
    if (Visited.at(nxt))
    {
      ans = -1;
      break;
    }
    else
    {
      Visited.at(nxt) = true;
      on = nxt;
      if (on == 2)
      {
        break;
      }
    }
  }
  cout << ans << endl;
}
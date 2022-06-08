
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int a[N];
  int count = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  int b = 0;

  while (a[b] == 2)
  {
    b = a[b] - 1;
    count++;
    if (a[b] == 2)
    {
      cout << count << endl;
      break;
    }
  }
}

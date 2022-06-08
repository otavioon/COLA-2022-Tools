#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> c(3, vector<int>(3));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      cin >> c[i][j];
  bool res = false;
  for (int i = 0; i <= c[0][0]; i++)
  {
    int a0 = i;
    int b0 = c[0][0] - a0;
    for (int j = 0; j <= c[1][1]; j++)
    {
      int a1 = j;
      int b1 = c[1][1] - a1;
      for (int k = 0; k <= c[2][2]; k++)
      {
        int a2 = k;
        int b2 = c[2][2] - k;
        if (   a0 + b1 == c[0][1]
            && a0 + b2 == c[0][2]
            && a1 + b0 == c[1][0]
            && a1 + b2 == c[1][2]
            && a2 + b1 == c[2][1]
            && a2 + b0 == c[2][0])
        { res = true; break;}
      }
    }
  }
  cout << (res ? "Yes" : "No") << endl;
}
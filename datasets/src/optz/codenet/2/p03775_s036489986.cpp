#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
int main()
{
  long long N;
  cin >> N;
  vector<long long> v;
  v.push_back(1LL);
  long long a = sqrt(N);
  long long i = 2, j = 1, t;
  int n;
  while (i < a)
  {
    if (0LL == N % i)
    {
      N /= i;
      n = v.size();
      t = pow(i, j);
      for (int k=0; k<n; ++k)
      {
        v.push_back(v[k] * t);
      }
      ++j;
    }
    else
    {
      ++i;
      j=1;
    }
  }
 
  long long b = 1000000000000;
  n = v.size();
  for (int k=n-1; k>=0; --k)
  {
    if (k>=a && b > v[k])
    {
      b = v[k];
    }
  }
 
  int c = 0;
  while (b > 0)
  {
    b /= 10;
    ++c;
  }
  cout << c << endl;
  return 0;
}
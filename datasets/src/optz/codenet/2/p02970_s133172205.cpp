#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ul;
typedef signed long long ll;

mt19937 mt(time(nullptr));
// uniform_int_distribution< int > rand_int(0, 10) // rand[0, 10] inclusive

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed;
  int n, d;
  cin >> n >> d;
  cout << (n-1)/(d*2+1)+1 << endl;
  return 0;
}

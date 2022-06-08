#include <iostream>
#include <math.h>

using ll = long long;

using namespace std;

int keta(ll n) {
  ll foo = 10;
  for (int i = 1; i < 100; i++) {
    if (foo > n) {
      return i;
    }
    foo *= 10;
  }

  return -1;
}

int main()
{
  ll N;
  cin >> N;

  ll n = ceil(sqrt((long double)N));

  for (ll i = n; i <= N; i++) {
    if (N % i == 0) {
      cout << keta(i) << endl;
      return 0;
    }
  }

  return 0;
  
}

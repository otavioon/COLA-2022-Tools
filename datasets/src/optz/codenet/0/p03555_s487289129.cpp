#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <limits.h>
#include <cmath>
#include <queue>
#include <map>
#include <iomanip>
#include <random>
#include <fstream>
#define rep(i, n) for (int i = 0; i < n; i++)
#define PI 3.14159265358979323846
#define MOD 1000000007
using namespace std;
using ll = long long;

const int MAX = 1000000;

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll gcd(ll a, ll b)
{
  ll r;
  while ((r = a % b))
  {
    a = b;
    b = r;
  }
  return b;
}

template <class T> struct cord{
  T x,y;
};

template <class T> double dist(cord<T> a, cord<T> b){
  T dx=a.x-b.x;
  T dy=a.y-b.y;
  return sqrt(dx*dx+dy*dy);
}

int main()
{

  //cout << fixed << setprecision(10);

  string c1,c2; cin >> c1 >> c2;
  if (c1[0]==c2[2]&&c1[1]==c2[1]&&c1[2]==c2[0]){
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}

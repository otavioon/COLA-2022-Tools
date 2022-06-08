#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = pow(10, 9) + 7;
//const int MOD = 998244353;
//const int MOD = ;
int mod(int A, int M) {return (A % M + M) % M;}
const int INF = 1LL << 60;
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
int myctoi(char C) {return C - 48;}
char myitoc(int N) {return '0' + N;}

signed main()
{
  int N, K;
  cin >> N >> K;
  vector<bool> D(10, false);
  for (int i = 0; i < K; i++)
  {
    int d;
    cin >> d;
    D.at(d) = true;
  }
  
  while (true)
  {
    int n = N;
    bool ok = true;
    while (n > 0)
    {
      if (D.at(n % 10))
      {
        ok = false;
        break;
      }
      n /= 10;
    }

    if (ok)
    {
      cout << N << endl;
      return 0;
    }

    N++;
  }
}
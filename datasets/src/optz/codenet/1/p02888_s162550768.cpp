#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << (A) << '\n'; exit(0);}

int main()
{
  ll N;
  cin >> N;
  vector<ll> X(1010, 0);
  for (ll i = 0; i < N; i++)
  {
    ll L;
    cin >> L;
    X.at(L)++;
  }

  ll ans = 0;
  for (ll a = 1; a <= 1000; a++)
  {
    if (X.at(a) == 0)
      continue;
    
    for (ll b = a; b <= 1000; b++)
    {
      if (X.at(b) == 0)
        continue;
      
      for (ll c = b; c <= 1000; c++)
      {
        if (X.at(c) == 0)
          continue;
        if (c >= a + b)
          break;

        if (a == b && b == c)
          ans += X.at(a) * (X.at(b) - 1) * (X.at(c) - 2) / 6;
        else if (a == b)
          ans += X.at(a) * (X.at(b) - 1) * X.at(c) / 2;
        else if (b == c)
          ans += X.at(a) * X.at(b) * (X.at(c) - 1) / 2;
        else
          ans += X.at(a) * X.at(b) * X.at(c);
      }
    }
  }
  cout << ans << endl;
}
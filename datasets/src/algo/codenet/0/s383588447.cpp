#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
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
  string S;
  cin >> S;
  string s = S;
  S += S;
  ll N = S.size();
  ll K;
  cin >> K;

  bool same = true;
  for (ll i = 0; i < N - 1; i++)
  {
    if (S.at(i) != S.at(i + 1))
    {
      same = false;
      break;
    }
  }
  if (same)
    FINALANS(N / 2 * K / 2);

  ll a0 = 0, a1 = 0;
  for (ll i = 0; i < N - 1; i++)
  {
    if (S.at(i) == S.at(i + 1))
    {
      S.at(i + 1) = '?';
      if (i + 1 < N / 2)
        a0++;
      else
        a1++;
    }
  }
  ll ans = a0 + (K - 1) * a1;
  cout << ans << endl;
  cerr << a0 << " " << a1 << endl;

  return 0;

  cerr << endl;
  string T = s;
  for (ll i = 0; i < K - 1; i++)
  {
    T += s;
  }
  ll tmp = 1;
  ll ans0 = 0;
  for (ll i = 0; i < T.size() - 1; i++)
  {
    if (T.at(i) == T.at(i + 1))
      tmp++;
    else
    {
      ans0 += tmp / 2;
      tmp = 1;
    }
  }
  ans0 += tmp / 2;
  cerr << S << endl
       << T << endl;
  cerr << ans0 << endl;
}
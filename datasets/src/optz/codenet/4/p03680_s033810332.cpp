// B - Trained?
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define rep(i, m, n) for (lli i = m; i < (n); i++)
#define repe(i, m, n) for (lli i = m; i <= (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((lli)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define _GLIBCXX_DEBUG
const lli INF = 2147483647;
const lli MINF = -2147483648;
const lli LINF = 9223372036854775807;
const lli MOD = 1000000007; //10^9+7
const double PI = acos(-1);
#define SORT(n) sort(n.begin(), n.end())
#define SORTR(n) sort(n.begin(), n.end(), greater<int>())
#define REV(n) reverse(n.begin(), n.end())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#pragma GCC optimize("Ofast")
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vlli = vector<lli>;
using vs = vector<string>;
using ll = long long;
// vector入力
template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
  for (T &x : vec)
    is >> x;
  return is;
}
// vector出力
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec)
{
  // os << '{';
  for (int i = 0; i < vec.size(); i++)
  {
    os << vec[i] << (i + 1 == vec.size() ? "" : "");
  }
  // os << '}';
  return os;
}
// aよりもbが大きいならばaをbで更新する(更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b; // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する(更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T &b)
{
  if (a > b)
  {
    a = b; // aをbで更新
    return true;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli a, b, c, e, f, h, k, n, w, ans = 0, count = 0;
  string s, t;
  vector<pair<string, pair<lli, lli>>> pr;
  cin >> n;
  vlli d(n), z;
  set<lli> g;
  rep(i, 0, n)
  {
    cin >> d[i];
    // z.pb(d[i] - 1);
    // d[i]--;
  }
  rep(i, 0, n)
  {
    if (d[i] != 2)
    {
      ans++;
    }
  }
  if (ans == n)
  {
    cout << -1 << endl;
    return 0;
  }

  a = d[0];
  if (a == 2)
  {
    cout << count << endl;
    return 0;
  }

  while (!g.count(a))
  {
    if (count >= n)
    {
      cout << -1 << endl;
      return 0;
    }
    g.insert(a);
    a = d[a - 1];
    count++;
    if (a == 2)
    {
      cout << count + 1 << endl;
      return 0;
    }
  }
  // rep(i, 0, n)
  // {
  //   if (ans == 1)
  //   {
  //     cout << count << endl;
  //     return 0;
  //   }
  //   if (count >= n)
  //   {
  //     cout << -1 << endl;
  //     return 0;
  //   }
  //   count++;
  //   ans = d[ans];
  // }
  cout << -1 << endl;
}
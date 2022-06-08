#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
int n;
ll a, b;
vector<ll> h;

bool calc(ll m){
  ll sum = 0;
  for(int i = 0; i < n; i++){
    ll tmp = h[i] - m * b;
    if(tmp <= 0)continue;
    sum += (tmp + a - b - 1) / (a - b);
  }
  return (sum <= m);
}

int main(int argc, char const* argv[])
{
  cin >> n >> a >> b;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    h.pb(x);
  }
  ll ld = 0;
  ll rd = 1e10;
  while(rd - ld > 1){
    ll md = (ld + rd) / 2;
    if(calc(md))rd = md;
    else ld = md;
  }
  cout << rd << endl;
	return 0;
}

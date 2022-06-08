#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define pb(x) push_back(x)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;

int main()
{
    int n;
    cin >> n;
    multiset<ll> ball;
    rep(i,n){
        ll ai;
        cin >> ai;
        ball.insert(ai);
    }
    ll ans = 0;
    while (!(ball.empty())){
        auto itr = ball.end();
        itr--;
        ll last = *itr;
        ball.erase(itr);
        repr(k,31,-1){
            if ((1ll<<k)<last)
                break;
            auto x = ball.find((1ll << k) - last);
            if (x!=ball.end()){
                ans++;
                ball.erase(x);
                break;
            }
        }
    }
    cout << ans << endl;
}
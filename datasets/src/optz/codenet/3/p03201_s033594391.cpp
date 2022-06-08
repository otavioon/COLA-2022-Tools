#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll a[212345];
    ll p[50];
    unordered_map<ll, int> mp;
    vector<ll> v;

    cin >> n;
    REP(i, n)
    {
        cin >> a[i];
        if (!mp[a[i]])
            v.push_back(a[i]);
        mp[a[i]]++;
    }

    SORT(v);

    bool used[212345] = {false};

    p[0] = 1;
    REP(i, 32)
    p[i + 1] = p[i] * 2;

    int res = 0;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (!mp[v[i]])
            continue;

        ll t;
        for (int j = 1; j <= 32; j++)
        {
            if (p[j] - v[i] <= v[i] && mp[p[j] - v[i]])
            {
                t = p[j] - v[i];
                break;
            }
        }

        if (t == v[i])
        {
            res += mp[v[i]] / 2;
        }
        else
        {
            ll t_ = min(mp[t], mp[v[i]]);
            res += t_;
            mp[t] -= t_;
        }
    }

    cout << res << endl;

    return 0;
}

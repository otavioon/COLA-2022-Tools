#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;

struct eratosthenes
{
    int n;
    vector<int> f;
    vector<pair<int, int>> primes;

    eratosthenes(int n) : f(n + 1)
    {
        ll i, j;
        f[0] = f[1] = -1;
        for (i = 2; i <= n; i++)
        {
            if (!f[i])
            {
                f[i] = i;
                primes.push_back(make_pair(i, 0));
                for (j = i * i; j <= n; j += i)
                {
                    if (!f[j])
                    {
                        f[j] = i;
                    }
                }
            }
        }
    }

    vector<int> genosis(int x)
    {
        vector<int> g;

        while (x != 1)
        {
            g.push_back(f[x]);
            x /= f[x];
        }

        return g;
    }

    vector<pair<int, int>> genosiscount(int x)
    {
        vector<pair<int, int>> gc;
        vector<int> g = genosis(x);

        if (g.empty() == 1)
        {
            return {};
        }

        gc.push_back(make_pair(f[x], 0));

        for (auto &i : g)
        {
            if (gc.back().first == i)
            {
                gc.back().second++;
            }
            else
            {
                gc.push_back(make_pair(i, 1));
            }
        }

        return gc;
    }
};

int main(void)
{
    int N, M;
    int a;
    eratosthenes e(1e5 + 1);
    int i, j;
    ll lcm = 1;
    int ans = 0;

    cin >> N >> M;

    rep(i, 0, N - 1)
    {
        cin >> a;
        a /= 2;

        for (auto &x : e.genosiscount(a))
        {
            for (auto &y : e.primes)
            {
                if (x.first == 2)
                {
                    if (x.second > 0 && x.second != y.second)
                    {
                        cout << 0 << endl;
                        return 0;
                    }
                }

                if (x.first == y.first && x.second > y.second)
                {
                    y.second = x.second;
                }

                if (x.first < y.first)
                {
                    break;
                }
            }
        }
    }

    for (auto &y : e.primes)
    {
        rep(i, 1, y.second)
        {
            lcm *= y.first;
        }
    }

    i = 1;

    while (lcm * i <= M)
    {
        ans++;
        i += 2;
    }

    cout << ans << endl;
}
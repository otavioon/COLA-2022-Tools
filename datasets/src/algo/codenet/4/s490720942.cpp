// LUL
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define FILE "parade"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const ull ULLINF = numeric_limits<ull>::max();
const double PI = acos(-1.0);

int main()
{
//    freopen(FILE".in", "r", stdin);
//    freopen(FILE".out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    set<int> d;
    for(int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        d.insert(a);
    }
    for(int i = n; ; i++)
    {
        int f = i;
        bool good = 1;
        while(f)
        {
            if(d.find(f % 10) != d.end())
            {
                good = 0;
                break;
            }
            f /= 10;
        }
        if(good)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}

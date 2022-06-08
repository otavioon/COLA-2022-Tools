#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void _main()
{
    int N;
    cin >> N;

    multiset<int, greater<int>> ms;
    rep(i, 0, N)
    {
        int A;
        cin >> A;
        ms.insert(A);
    }

    int ans = 0;

    while (!ms.empty())
    {
        const int x = *ms.begin();
        ms.erase(ms.begin());

        int two = 1;
        while (two <= 2000000000)
        {
            if (two > x) break;
            two *= 2;
        }

        const int y = two - x;
        auto it = ms.find(y);
        if (it != ms.end())
        {
            ++ans;
            ms.erase(it);
        }
    }

    cout << ans << endl;
}

#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <string>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define f first
#define s second
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define eb emplace_back
#define in insert
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define FOR(i, n, x) for(int i = x; i < n; i++)
#define OUT(a, e) FOR(i, e, 0) cout << a[i] << ' '
#define OUTV(a) for(auto i : a) cout << i << ' ';
#define maxim(a, n, mx) FOR(i, n, x)mx = max(mx, a[i]);

using namespace std;
string alph = "abcdefghijklmnopqrstuvwxyz";
int used[205];
int main()
{
    string s; cin >> s;
    ll k; cin >> k;
    int n = s.size();
    ll cnt = 0;
    FOR(i, n, 1)
    {
        if(s[i - 1] == s[i] && !used[i - 1])
        {
            cnt++;
            used[i] = 1;
        }
    }
    int fl = 0;
    if(s[0] == s[n - 1])
    {
        if(!used[n - 1])
        {
            cnt++;
            fl = 1;
        }
    }
    if(fl)cout << cnt * k - 1;
    else cout << cnt * k;
	return 0;
}

//22222222222222222222222
//ada(2asd)
//(2(3AC)A)

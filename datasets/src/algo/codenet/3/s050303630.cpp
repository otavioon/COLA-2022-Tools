#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
void vshow(int v[], int n)
{
    return;
    rep(i, n)
    {
        cerr << v[i] << (i < n - 1 ? "," : "");
    }
    cerr << endl;
}

int binarySearch(int v[], int n, int t)
{
    int r = n;
    int l = -1;
    while (l + 1 != r)
    {
        int med = (r + l) / 2;
        if (v[med] > t)
        {
            r = med;
        }
        else
        {
            l = med;
        }
    }
    return r;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    ll ans = 0;
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    rep(i, n)
    {
        cin >> c[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    vshow(a, n);
    vshow(b, n);
    vshow(c, n);
    rep(i, n)
    {

        ll acandidate = binarySearch(a, n, b[i]);
        ll ccandidate = n - binarySearch(c, n, b[i]);
        dumpl(acandidate);
        dumpl(ccandidate);
        ans += acandidate * ccandidate;
    }
    cout << ans << endl;
    return 0;
}

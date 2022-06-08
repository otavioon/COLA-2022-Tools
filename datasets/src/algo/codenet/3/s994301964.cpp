#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[100005], b[100005], c[100005], n;
    ll ans = 0, nowa = 0, nowc = 0;

    cin >> n;

    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    for (int i=0; i<n; i++) scanf("%d",&b[i]);
    for (int i=0; i<n; i++) scanf("%d",&c[i]);

    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);

    for (int i = 0; i < n; i++)
    {
        while ((a[nowa] < b[i]) && (nowa < n)) nowa++;
        while ((c[nowc] <= b[i]) && (nowc < n)) nowc++;
        ans = ans + nowa*(n - nowc);
    }
    cout << ans << endl;

    return 0;
}

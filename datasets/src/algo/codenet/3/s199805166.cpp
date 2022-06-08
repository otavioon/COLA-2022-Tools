#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <stack>
#include <vector>
#define INF 0x3f3f3f3f
#define MOD 1000000009
# define FOR(i,a,n) for(register int i=a; i<=n; ++i)
# define FDR(i,a,n) for(register int i=a; i>=n; --i)
typedef long long ll;
using namespace std;
int a[100005];
int b[100005];
int c[100005];
ll d[100005];
ll e[100005];
int main()
{
    int n;
    scanf("%d", &n);
    FOR(i,1,n)
    {
        scanf("%d", &a[i]);
    }
    FOR(i,1,n)
    {
        scanf("%d", &b[i]);
    }
    FOR(i,1,n)
    {
        scanf("%d", &c[i]);
    }
    sort(a+1, a+n+1);
    sort(b+1, b+1+n);
    sort(c+1, c+1+n);
    ll ans = 0;
    memset(d, 0, sizeof(d));
//    int mins = lower_bound(c+1, c+1+n, b[n])-c;
    int k = 1;
    for(int i = 1; i <= n; i++)
    {
        while(b[i] >= c[k] && k <= n){k++;}
        d[i] = n-k+1;
//        cout << n-k+1 << endl;
    }
    for(int i = n; i >= 1; i--)
    {
        e[i] = e[i+1]+d[i];
    }
    k = 1;
    for(int i = 1; i <= n; i++)
    {
        while(a[i] >= b[k] && k <= n){k++;}
//        if(k >= n)k--;
//        if(kk >= n)kk--;
        ans += e[k];
//        cout << ans << endl;
    }
    printf("%lld\n", ans);
    return 0;
}

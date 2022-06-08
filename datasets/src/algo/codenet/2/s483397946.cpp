#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5;
int n, ans;
multiset<int, greater<int> > S;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int i, j;

    scanf("%d", &n);
    for(i=0; i<n; i++) { int x; scanf("%d", &x); S.insert(x); }

    while(!S.empty())
    {
        int x=*S.begin();
        S.erase(S.begin());
        for(i=1; i<=x; i*=2);
        i-=x;
        if(S.find(i)!=S.end()) { S.erase(i); ans++; }
    }

    printf("%d", ans);

    return 0;
}

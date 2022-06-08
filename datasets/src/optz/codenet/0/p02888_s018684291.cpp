#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans = 0;
    cin >> n;
    deque<int>dq(n);
    for(int i = 0;i < n;++i)
        cin >> dq[i];
    sort(dq.begin(), dq.end());
    while(dq.size() > 2)
    {
        int a = dq[0];
        for(int j = 1;j < dq.size();++j)
        {
            int b = dq[j];
            if(a > b)   swap(a, b);
            int hi = lower_bound(dq.begin(), dq.end(), a + b) - dq.begin();
            ans += hi - j - 1;
        }
        dq.pop_front();
    }
    cout << ans;
    return 0;
}

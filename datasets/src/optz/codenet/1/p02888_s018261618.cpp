#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<ll> length(1005, 0);
    for(int i=0; i<N; i++)
    {
        int l;
        cin >> l;
        length[l]++;
    }

    vector<ll> cum(2005, 0);
    cum[0] = length[0];
    for(int i=1; i<2005; i++)
    {
        if(i < 1005) cum[i] = cum[i-1] + length[i];
        else cum[i] = cum[i-1];
    }

    ll ans = 0;
    for(int i=1; i<=1000; i++)
    {
        for(int j=i; j<=1000; j++)
        {
            ll sun;
            if(i==j)
            {
                sun = length[i] * (length[i]-1) * (length[i]-2) / 6;
                sun += length[i] * (length[i]-1) / 2 * (cum[i+j-1] - cum[i]);
            }
            else
            {
                sun = length[i] * length[j] * (length[j]-1) / 2;
                sun += length[i] * length[j] * (cum[i+j-1] - cum[j]);
            }
            ans += sun;
            // if(sun != 0) cout << "i:" << i << ", j:" << j << ", sun:" << sun << endl;
        }
    }
    cout << ans << '\n';

    return 0;
}

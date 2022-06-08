#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> length(1005, 0);
    for(int i=0; i<N; i++)
    {
        int l;
        cin >> l;
        length[l]++;
    }

    vector<int> cum(2005, 0);
    cum[0] = length[0];
    for(int i=1; i<2005; i++)
    {
        if(i < 1005) cum[i] = cum[i-1] + length[i];
        else cum[i] = cum[i-1];
    }

    int ans = 0;
    for(int i=1; i<=1000; i++)
    {
        for(int j=i; j<=1000; j++)
        {
            int sun = 0;
            if(i==j) sun += length[i] * (length[i]-1) * (length[i]-2 + cum[i+j-1] - cum[i]);
            else sun += length[i] * length[j] * (length[j]-1 + cum[i+j-1] - cum[j]);
            ans += sun;
        }
    }
    cout << ans << '\n';

    return 0;
}

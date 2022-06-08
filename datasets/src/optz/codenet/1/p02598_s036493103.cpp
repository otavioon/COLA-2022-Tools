#include <bits/stdc++.h>
using namespace std;

#define int long long
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define all(x) begin(x),end(x)

int mod = 1e9+7;
int inf = 4e18;
const int N = 5e5+5;
		
signed main()
{
    flash
    int tt = 1;
    //cin>>tt;
    while(tt--)
    {
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;++i)
		{
			cin>>arr[i];
		}
		int low=1,high = 1e9,mid,ans = -1;
		auto help = [&](int mid)
		{
			int cuts = 0;
			for(int i=0;i<n;++i)
			{
				cuts+= (arr[i]+mid-1)/mid -1;
			}
			return cuts<=k;
		};
		while(low<=high)
		{
			mid = low+(high-low)/2;
			if(help(mid))
			{
				ans = mid;
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
		cout<<ans<<"\n";		
    }
    return 0;
}

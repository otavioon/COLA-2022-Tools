#include<bits/stdc++.h>
using namespace std;
const int N = 6010100;
long long  n,k;
long long  S[N];
bool pd(int K)
{
	if(K<=0) return false;
	long long A = 0;
	for(int i = 1;i <= n;i++)
	{
		A += S[i]%K?S[i]/K:S[i]/K-1;
	}
	return A <= k;
}
int main()
{
	long long  ans = 0;
	scanf("%lld%lld",&n,&k);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&S[i]);
		ans= max(S[i],ans);
	}
	int r = ans,l = 1;
	while(l <= r)
	{
		long long mid = l+r>>1;
		if(pd(mid))
		{
			ans = min(ans,mid);
			r = mid-1;
		}
		else l = mid+1;
	}
	cout<<ans<<endl;
	return 0;
}
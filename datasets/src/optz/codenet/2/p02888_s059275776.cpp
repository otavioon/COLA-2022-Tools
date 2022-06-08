#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
int l[2000];
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>l[i];
	}
	sort(l,l+n);
	for(int i=n-1;i>-1;i--)
	{
		for(int j=i-1;j>-1;j--)
		{
			ll tmp=upper_bound(l,l+n,l[i]+l[j]-1)-upper_bound(l,l+n,l[i]-l[j]);
			if(l[i]>l[i]-l[j] && l[i]<l[i]+l[j])
				tmp--;
			if(l[j]>l[i]-l[j] && l[j]<l[i]+l[j])
				tmp--;
			//cerr<<tmp<<endl;
			ans+=max(tmp,0LL);
		}
	}
	ans/=3;
	cout<<ans<<endl;
	return 0;
}
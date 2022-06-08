#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
#include<cmath>
#define Max zhi5968
typedef long long ll;
using namespace std;

int main ()
{
	int n,i,a[10010],b[10010],c[10010],aa[10010],bb[10010];
	cin>>n;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	int tmp1=0,tmp2=0,tmp3=0;
	sort(a,a+n); sort(b,b+n); sort(c,c+n);
	for(i=0;i<n;i++)
	{
		while(b[i]>=c[tmp3])
		{
			if(tmp3==n)
				break;
			tmp3++;
		}
		bb[i]=n-tmp3;
	//	cout<<i<<" "<<bb[i]<<endl;
	}
	for(i=n-2;i>=0;i--)
	{
		bb[i]+=bb[i+1];
	//	cout<<"b="<<bb[i]<<endl;
	}
	ll ans=0;
	for(i=0;i<n;i++)
	{
		while(a[i]>=b[tmp2])
		{
			if(tmp2==n)
				break;
			tmp2++;
		}
	//	cout<<tmp2<<" "<<bb[tmp2]<<endl;
		ans+=bb[tmp2];
	}
	cout<<ans<<endl;
	return 0;
}
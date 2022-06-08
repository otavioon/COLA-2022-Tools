#include<bits/stdc++.h>
#define P printf
#define warn cout<<'\a'
#define SC(n,a) cout<<fixed<<setprecision(n)<<q
#define srt(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define srz(a,n) sort(a,a+n)
#define rez(a,n) reverse(a,a+n)
#define mem(a,f) memset(a,f,sizeof(a))
#define rep(i,n) for(long long i=0;i<(long long)n;i++)
#define rep2(i,n) for(long long i=1;i<(long long)n;i++)
#define ll long long
using namespace std;
ll power[46];
void powermake()
{
	power[0]=1;
	rep2(i,46) power[i]=power[i-1]*2;
}
int main()
{
	powermake();
	ll n;
	int t,ans=0;
	cin>>n;
	ll a[n];
	rep(i,n) cin>>a[i];
	ll b[n];
	rep(i,n){
		rep(j,46)
		{
			ll m=power[j]-a[i];
			rep2(k,n)
				if(m==a[k])
					b[i]++;
		}
	}
	rep(i,n)
	{
		ll minv=2000000000;
		rep(j,46)
		{
			ll m2=power[j]-a[i];
			for(int k=i+1;k<n;k++)
			{
				if(a[k]==m2&&b[k]<minv&&b[k]!=-1)
				{
					minv=b[k];
					t=k;
				}
			}
		}
		ans++;
		b[t]=-1;
	}
	cout<<ans<<endl;
  return 0;
}
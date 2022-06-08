/*
 _     _    ___  ___  __ __ 
| |   | |  |__ \|__ \/_ /_ |
| |__ | |__   ) |  ) || || |
| '_ \| '_ \ / /  / / | || |
| |_) | |_) / /_ / /_ | || |
|_.__/|_.__/____|____||_||_|

*/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

#define N  100005

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		ll n;
		cin>>n;
		ll a[n+1],b[n];
		rep(i,1,n)cin>>b[i];
		a[1]=b[1];
		a[n]=b[n-1];
		rep(i,2,n)a[i]=min(b[i-1],b[i]);
		ll ans=0;
		rep(i,1,n+1)ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
}
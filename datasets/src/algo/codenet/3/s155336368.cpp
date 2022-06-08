#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[214514],b[214514],c[214514];

int main(){
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(a,a+n+1);
	sort(b,b+n+1);
	sort(c,c+n+1);
	a[n+1]=b[n+1]=c[n+1]=1e12;
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll oka=0,nga=n+1,mida;
		while(nga-oka>1){
			mida=(oka+nga)/2;
			if(a[mida]<b[i])oka=mida;
			else nga=mida;
		}
		ll okc=n+1,ngc=0,midc;
		while(-ngc+okc>1){
			ll midc=(okc+ngc)/2;
			if(c[midc]>b[i])okc=midc;
			else ngc=midc;
		}
		ans+=oka*(n+1-okc);
	}
	cout<<ans;
	return 0;
}

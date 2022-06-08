#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const double esp=1e-6;

double a[N];
ll n,k;

ll count(double x){
	ll res=0;
	for(ll i=0;i<n;i++)
		res+=(ll)ceil(a[i]/x)-1;
	return res;
}
void work(){
	
	double ma=0;
	cin>>n>>k;
	for(ll i=0;i<n;i++)
		scanf("%lf",&a[i]), ma=max(ma,a[i]);
	double l=1,r=ma;
	double ans=r;
	while(r-l>esp){

		double mid=(r+l)/2;

		ll tim=count(mid);
//cout<<ma<<endl;
//cout<<mid<<" "<<tim<<endl;		
		if(tim<=k)	r=mid, ans=mid;
		else l=mid;
	}
	cout<<(ll)ceil(ans)<<endl;
	return ;
}

int main(){
	//work();
//freopen("C:\\Users\\lenovo\\Desktop\\in.txt","r",stdin);
	work();
	return 0;
}

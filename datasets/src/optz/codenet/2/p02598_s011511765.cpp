#include<bits/stdc++.h> 
using namespace std;
long long n,m;
double a[200010];
bool check(double x){
	long long s=0;
	for(long long i=1;i<=n;i++)
	s=s+(a[i]-0.0001)/x;
	if(s<=m)return true;
	else return false;
}
int main(){
	cin>>n>>m;
	double ss=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		ss=max(ss,a[i]);
	}
	double l=1,r=ss;
	for(int i=1;i<=50;i++){
		double mid=(l+r)/2.0;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout<<fixed<<setprecision(0)<<r<<"\n";
	return 0;
}

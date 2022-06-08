#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	long long int n;
	cin>>n;
	long long int a[n+5],b[n+5],c[n+5],i,s=0,a1,a2;
	
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)cin>>b[i];
	for(i=1;i<=n;i++)cin>>c[i];
	
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	sort(c+1,c+1+n);
	
	for(i=1;i<=n;i++){
		a1=n;a2=1;
		while(c[a1]>=b[i] && a1>0)a1--;
		a1=n-a1;
		while(a[a2]<=b[i] && a2<=n)a2++;
		a2--;
		s=s+a1*a2;
	}
	
	cout<<s<<endl;
	return 0;
}
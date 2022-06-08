#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,a,b,x=0;
	cin>>n>>a>>b;
	long long h[n];
	for(int i=0;i<n;i++) cin>>h[i];
	sort(h,h+n);
	for(;h[n-1]>0;x++){
		for(int i=0;i<n-1;i++){
			h[i]-=b;
		}
		h[n-1]-=a;
		sort(h,h+n);
	}
	cout<<x<<endl;
	return 0;
}


#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
int a[maxn],b[maxn],c[maxn];
ll sum; 
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++) cin>>c[i];
	int a1=0,b1=0,c1=0;
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	for(int i=0;i<n;i++){
		b1=b[i];
		while(a[a1]<b1&&a1<n)a1++;
		while(c[c1]<=b1&&c1<n)c1++;
		sum+=a1*(n-c1);
	}
	cout<<sum;
	return 0;
}
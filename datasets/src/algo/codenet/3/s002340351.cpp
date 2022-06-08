#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,A=0;
	cin>>n;
	int a[n],b[n],c[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++) cin>>c[i];
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	for(int x=0;x<n;x++) for(int y=0;y<n;y++) if(b[y]>a[x]) for(int z=0;z<n;z++) if(c[z]>b[y]) A++;
	cout<<A; 
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//int n,a[50000],b[50000],c[50000];
	int n,a[100001],b[100001],c[100001];
	int ans=0;
	bool flag=0;
	int ab=0,bc=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	/*
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(a[i]>=b[j]){
				break;
				flag=1;
			}
			ab++;
		}
		if(flag==1)break;
	}
	flag=0;
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>0;j--){
			if(b[i]>=c[j]){
				break;
				flag=1;
			}
			bc++;
		}
		if(flag==1)break;
	}
	*/
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=0;j--){
			if(a[i]<=b[j]){
			for(int k=n-1;k>=0;k--){
				if(b[j]>=c[k]){break;}
					ans++;	
			}
			}else break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

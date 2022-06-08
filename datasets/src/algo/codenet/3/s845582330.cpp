#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//int n,a[50000],b[50000],c[50000];
	int n,a[100000],b[100000],c[100000];
	
	int ans=0;
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

	for(int i=n;i>0;i--){
		for(int j=n;j>0;j--){
			if(a[i]>b[j])break;
			for(int k=n;k>0;k--){
				if(b[j]>c[k])break;
					ans++;	
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}

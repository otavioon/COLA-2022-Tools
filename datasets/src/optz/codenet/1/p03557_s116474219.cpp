#include <iostream>
using namespace std;
int main(){
	long long int n,a[100000],b[100000],c[100000];
	//int n,a[100000],b[100000],c[100000];
	
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
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]<b[j]){
			for(int k=0;k<n;k++){
				if(b[j]<c[k]){
					ans++;
				}
			}
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}

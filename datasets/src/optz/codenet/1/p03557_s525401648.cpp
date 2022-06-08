#include <bits/stdc++.h>
using namespace std;
int k=0;
int n;
int a[100005],b[100005],c[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			for(int z=1;z<=n;z++){
				if(a[x]<b[y]){
					if(b[y]<c[z]){
						k++;
					}
				}
			}
		}
	}
	cout<<k<<endl;
}
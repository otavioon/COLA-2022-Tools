#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;	cin>>n;
	int now=1;
	int ans=0;
	bool flag=false;

	for(int i=1;i<=n;i++){
		int a;	cin>>a;
		if(flag==false){
			if(now==i){
				ans++;
				if(a==2){
					flag=true;
				}
				now=a;
			}
		}
	}

	if(flag==false)ans=-1;



	cout<<ans<<endl;

	return 0;
}

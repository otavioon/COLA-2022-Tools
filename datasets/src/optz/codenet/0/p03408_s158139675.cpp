#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,cnt=0,ans=-10000;
	string s[100],t[100];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>t[i];
	}
	string f;
	for(int i=0;i<n;i++){
		f=s[i];
		cnt++;
		for(int j=i+1;j<n;j++){
			if(s[j]==f){
				cnt++;
			}
		}
		for(int j=0;j<m;j++){
			if(t[j]==f){
				cnt--;
			}
		}
		if(cnt>ans){
			ans=cnt;
		}
		cnt=0;
	}
	if(ans<0){
		cout<<0<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}

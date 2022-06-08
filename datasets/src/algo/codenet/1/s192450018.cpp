#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[4][4],sum=0,s;
	for(int i=1;i<=9;i++){
		cin>>s;
		sum+=s;
	}
	if(sum%3==0)cout<<"Yes";
	else cout<<"No";
}
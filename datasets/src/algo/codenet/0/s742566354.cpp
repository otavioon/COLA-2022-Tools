#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#define LL long long
using namespace std;

string s;
LL k,num=0,ans=0,last=0;
LL vis=0,viss=0,check=0;

int main(){
	cin>>s>>k;
	if(s.length()==1){
		cout<<k/2<<endl;
		return 0;
	}
	for(int i=0;i<s.length()-1;i++){
		if(s[i]==s[i+1])s[i+1]='-',num++;
	}
	for(int i=0;i<s.length();i++){
		if(s[i]==s[0]) vis++;
		else break;
	}
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]==s[s.length()-1]) viss++;
		else break;
	}
	if(s[0]==s[s.length()-1]){
		last=1;
		if((vis+viss)%2==1) check=1;
	}
	if(check){
		ans=num*k+(k-1)*((vis+viss)/2);
	}
	else ans=(num*k+last*(k-1));
	cout<<ans<<endl;
}
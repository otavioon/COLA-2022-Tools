#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;	cin>>s;
	long long k;	cin>>k;
	long long tmp=0;

	for(int i=0; i<s.size(); i++){
		if(s[(i-1<0? s.size()-1:i-1)]==s[i] && s[i]==s[i+1]){
			s[i]='.';
			tmp++;
		}else if(s[i]==s[i+1]){
			s[i+1]='.';
			tmp++;
		}
	}

	tmp*=k;
	//cout<<s<<endl;
	cout<<tmp<<endl;


	return 0;
}

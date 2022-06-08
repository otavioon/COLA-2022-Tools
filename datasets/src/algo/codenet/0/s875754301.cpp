#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define until(x) while(!(x))
#define unless(x) if(!(x))
#define all(x) (x).begin(),(x).end()

int32_t main(){
	string s;
	int k;
	cin>>s>>k;
	int st=0,fn=0,md=0;
	int n = s.length();
	for(int i=0;s[i]==s[0];i++){
		st++;
	}
	for(int i=n-1;s[i]==s[0];i--){
		fn++;
	}
	for(int i=st+1;i<n;i++){
		if(s[i-1]==s[i]){
			md++;
			i++;
		}
	}
	if(st==n){
		cout<<(n/2)*k;
		return 0;
	}
	if(s[0]!=s[n-1]){
		cout<<st/2 + md*k;
	}
	else {
		cout<<(st/2 + (st+fn)/2*(k-1) + md*(k-1) + fn/2);
	}
}

#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int main(){
	string s;int K;cin>>s>>K;
	int n=s.size();
	s+=s;
	ll a=0,b=0;
	rep(i,n){
		if(s[i]==s[i+1]){
			s[i+1]='?';
			if(i+1<n)a++;
			else b++;
		}
	}
	cout<<a*K+b*(K-1)<<endl;
}
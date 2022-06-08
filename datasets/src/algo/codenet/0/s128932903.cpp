#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	string s; cin>>s;
	ll k; cin>>k;
	ll n=s.length();
	ll x=0; ll c=0;
	bool ok=true;
	for(ll i=1;i<n;i++) if(s[0]!=s[i]) {ok=false; break;}

	if(ok){
		cout<<(n*k)/2; return 0;
	}	
	
	ll lc=-1;
	for(ll i=1;i<n;i++){
		if(s[i]==s[i-1]){
			if(lc==i-1) continue;
			c++; lc=i;
		}
	}
  
  if(s[0]==s[n-1] and lc != n-1) x++;

	cout<<(k-1)*x + k*c;

}

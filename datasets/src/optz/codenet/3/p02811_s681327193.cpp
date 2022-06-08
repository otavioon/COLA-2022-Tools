/*
	In the name of ALLAH
	Author : Raashid Anwar
*/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define mod 1000000007


int power(int a,int b) {
	int r=1;
	while(b) {
		if(b&1)
			r=(r*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return r;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x,k;
	cin>>x>>k;
	if(x*500>=k)
		cout<<"Yes\n";
	else
		cout<<"No\n";
}
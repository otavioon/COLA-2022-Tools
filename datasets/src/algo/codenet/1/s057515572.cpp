#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define pb push_back
#define pf push_front
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
 
ll gcd(ll x, ll y) {
	if(y==0) return x;
	return gcd(y,x%y);	
}

ll lcm(ll x, ll y) {
	ll z=gcd(x,y);
	return x/z*y;
}

int main()
{
	int c[9];
	rep(i,9) cin >> c[i];
	int a=c[0]+c[4]+c[8];
	int b=c[1]+c[5]+c[6];
	int d=c[2]+c[3]+c[7];
	if(a==b && b==d) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}

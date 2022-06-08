/*
Author: Babin Dutta
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define f(i,n) for(int i=0;i<n;i++)
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define all(v) v.begin(),v.end()
#define endl "\n"
#define inf 1e18

void solve(){
	int n; cin>>n;
	ll b[n-1];
	f(i,n-1) cin>>b[i];
	if(n == 2){
		cout<<2*b[0]<<endl;
		return;
	}
	ll ans = b[0] + b[n-2];
	cout<<ans<<endl;
	for(int i=0;i<n-2;i++) ans += min(b[i], b[i+1]);
	cout<<ans<<endl;
}

int main(){
	#ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
	boost;
	int t=1; //cin>>t;
	for(int i=1;i<=t;i++) solve();
	return 0;
}
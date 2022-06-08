#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store") // to restrict undesirable precision
#pragma GCC optimize ("-fno-defer-pop")// to pop argument of function as soon as it returns
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define takeline cin.ignore();
#define sc second
#define N 3000005
#define endl "\n"
#define mod 1000000007
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string s;
	cin>>s;
	ll i,j,k,l,n=s.length();
	cin>>k;

	if(n==1){
		l=k/2;
		cout<<l;return 0;
	}
	if(n==2){
		if(s[0]==s[1]){
			cout<<k;return 0;
		}
		else{
			cout<<"0";return 0; 
		}
	}
	if(s[0]==s[n-1]){
		ll a=0,b=0;
		i=0; j=n-1;
		while(i<j){
			l=0;
			if(s[i]==s[0]){
				a++; i++;
			}
			else l++;
			if(s[j]==s[n-1]){
				b++; j--;
			}
			else l++;
			if(l==2) break;
		}
		if(j<=i){
			ll ans=0;
			if(n%2){
				ans=((n+1)/2);
			}
			else{
				ans=(n/2);
			}
			cout<<ans*k;return 0;
		}
		l=0;
		for(i=0;i<n-1;i++){
			if(s[i]==s[i+1]){
				i++;l++;
			}
		}
		ll ans=l*k;
		if(a%2&&b%2) ans+=k;
		cout<<ans<<endl;
	}
	else{
		l=0;
		for(i=0;i<n-1;i++){
			if(s[i]==s[i+1]){
				i++;l++;
			}
		}
		cout<<(l*k);return 0;
	}
	return 0;
}
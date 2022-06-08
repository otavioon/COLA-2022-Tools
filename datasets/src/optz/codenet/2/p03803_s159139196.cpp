#include<bits/stdc++.h>
using namespace std;

#define fastio 			ios::sync_with_stdio(0);	cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(12);	
#define randomINT 		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define	newl 			cout<<"\n"
#define DISP(as)		for(auto it : as) cout<<it<<" ";newl;
#define all(x)         	(x).begin(),(x).end()
#define mset(x,val)    	memset(x,val,sizeof(x))
#define newl           	cout<<"\n"
#define pb             	push_back
#define mp             	make_pair
#define f 				first
#define s 				second
#define dline          cerr<<"///REACHED///\n";
#define deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll ,ll> 			pll;
typedef pair<ld,ld> 			pld;
typedef unordered_map<ll,ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5+7;
const ll 	MAX7 	= 	1e+7+7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9+7;
const ll 	N 		= 	2*1e6;

// <------------- Declare Variables Here ------------> //

ll T=1;
ll n,x,y,m;
string s,t;
//vll a;
// <------------- Implement Functions Here ----------> //



// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> x >> y;
	x--; y--;
	if(x==0) x=13;
	if(y==0) y=13;

	if(x > y) cout<<"Alice";
	else if(y > x) cout<<"Bob";
	else cout<<"Draw"; 
}

int main() {
	fastio;randomINT;
	//cin>>T;
	while(T--) {
		MAIN();
	}
	return 0;
}


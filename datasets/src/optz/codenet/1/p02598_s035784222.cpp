///////////////////// author : TrEbLeCleF /////////////////////
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define For(i, a) for (int i=0; i<(a); i++)
#define FORR(i,a,b) for (int i = (b)-1; i >= a; i--)
#define Forr(i,a) for (int i = (a)-1; i >= 0; i--)
/////////////////////////// ..... ///////////////////////////
#define deb(...) cerr << "[" << #__VA_ARGS__ << "] : [", DBG(__VA_ARGS__) 
void DBG() { cerr << "]\n";}
template<typename T, typename ...Args> void DBG(T first, Args... args){
cerr << first; if(sizeof...(args))cerr<<", "; DBG(args...); }
/////////////////////////// ..... ///////////////////////////
#define int ll
#define pb(x) push_back(x)
#define print(v,s,e) for(int i = s; i < e; i++)cout << v[i]<<" ";cout<<"\n";
#define INF 1e17
#define PI 3.14159265358979323846 
int del_x[4] = {-1, 1, 0, 0};
int del_y[4] = {0, 0, 1, -1};
int XX[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int YY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
/////////////////////////// GLOBAL ///////////////////////////
const int N = 2e5+10;
int a[N];
bool possible(int L, int k, int n){
	For(i,n){
		k -= (a[i]-1)/L;
	}
	return (k>=0?true:false);
}
/////////////////////////// GLOBAL ///////////////////////////
void solve(){
	int n, k; cin >> n >> k;
	For(i,n)cin >> a[i];
	int low = 1, high = 1e9;
	int ans = -1;
	while(low <= high){
		int mid = low + (high-low)/2;
		if(possible(mid,k, n)){
			ans = mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	} 
	cout << ans <<"\n";

	
}

int32_t main(){ 
	#ifndef ONLINE_JUDGE
		clock_t tStart = clock();
		freopen("TC", "r", stdin);
		//freopen("output.txt","w",stdout);
	#endif 
    ios_base:: sync_with_stdio(false); 
   	cin.tie(0); 
	int t=1;
	//cin >> t;
	for(int tt=1;tt<=t;tt++){
		//cout << "Case #"<<tt<<": ";
		solve();
	}
	#ifndef ONLINE_JUDGE
    	cerr << "\nRun Time -> "<<(double)(clock()-tStart)/CLOCKS_PER_SEC <<" sec\n";
    #endif
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <set>
#include <sstream>
using namespace std;
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define FOR(i,a,b) for(int i=a; i<(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort(ALL(x))
#define CLR(a) memset((a), 0 ,sizeof(a))
#define PB push_back
#define MP make_pair
#define SP << " " <<
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
const int INF = 1001001001;
const ll MOD = 1e9+7;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){std::fill((T*)array, (T*)(array+N),val);}


__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}


signed main(){
	string s; cin>>s;
	ll k; cin>>k;
	ll n = s.size();
	if(n==1) return cout<<k/2<<endl,0;

	ll cnt = 0;
	reps(i,n-1)	if(s[i-1]==s[i]) cnt++,i++;
	bool flg = false;
	if(s[0]==s[n-1]) flg = true;
	ll ans = cnt*k;

	int top = 1, btm = 1;
	reps(i,n-1){
		if(s[i]==s[0]) top++;
		else break;
	}
	REP(i,n-1){
		if(s[i]==s[n-1]) btm++;
		else break;
	}
	if(flg) if((btm%2)&&(top%2)) ans += k-1;
	if(top==n&&btm==n){
		return cout<<n*(k/2)<<endl,0;
	}
	cerr << cnt SP top SP btm << endl;
	cout << ans << endl;

  return 0;
}

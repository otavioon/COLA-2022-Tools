#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")
#pragma GCC optimize ("trapv")

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cin.exceptions(cin.failbit);
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define what_is(x) cerr << #x << " is " << x << endl;
#define wis cout<<endl<<"I already speak english, bitch"<<endl<<endl;
 
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef pair<ii,lli> iii;
typedef long double C; 

#define trace(args...) { string  _s =#args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);}
void err(istream_iterator<string> it){}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args){
    cerr <<  *it  << " : " << a << endl;
    err(++it, args...);
}

set<int> s;

bool des(int n){
	bool chi=true;
	while(n!=0){
		int dig=n%10;
		n/=10;
		if(s.count(dig)) return false;
	}
	return true;
}


int main(){
	fastio;
	int n,k; cin>>n>>k;
	rep(i,0,k){
		int foo; cin>>foo;
		s.insert(foo);
	}
	while(1){
		if(des(n)){
			cout<<n<<endl;
			break;
		}
		n++;
	}
	return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/

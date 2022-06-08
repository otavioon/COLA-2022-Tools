#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map
#define mtv(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)

vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out( 
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cout << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    stringstream ss; ss << H;
    cout << args[idx] << "- " << ss.str() << ", ";
    debug_out(args, idx + 1, LINE_NUM, T...);
}

bool isvalid(ll k, ll n, vector<ll>&v,ll cur){
	ll i,cou = 0;
	rep(i,0,n){
		if(v[i] > cur){
		cou += (v[i]/cur - 1);
	if(v[i] % cur)cou++;}
	}
	return cou <= k ;
}


void doit(){
	ll n,k,i,x;
	cin >> n >> k;
	vector< ll >v(n);
	for(i = 0; i < n; i++)cin>>v[i];
	ll low = 0LL ,high = *max_element(all(v)),mid,ans = 1e18;
	while(low <= high){
		mid = low + (high - low)/2;
		if(isvalid(k,n,v,mid)){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	//mtv(isvalid(k,n,v,292638192));
	cout << ans << nl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}

#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <numeric>
#include <iomanip>
#include <limits>
#include <set>
#include <map>
#include <type_traits>
#include <cstdint>

typedef long long ll;

using namespace std;

//素因数分解
void factoring(ll n, map<ll, ll>& mp) {
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			mp[i]++;
			n /= i;
		}
	}
	if (n != 1) mp[n]++;
}

//絶対値
template<class T, class U = std::make_unsigned_t<T>>
U SafeAbs( T x ) {
    return x < 0 ? -static_cast<uintmax_t>(x) : x;
}

//最大・最小
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

//xのn乗
ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
//xの逆元
ll mod_inv(ll x, ll mod) {//O(log(mod))
    return mod_pow(x, mod - 2, mod);
}

//nCr
ll ncr(ll n, ll r, ll mod){
	ll res=1;
	ll num=1,den=1;
	for(ll i=n;i>=n-r+1;i--){
		(den*=i)%=mod;
	}
	for(ll i=1;i<=r;i++){
		(num*=i)%=mod;
	}
	
	res=den*mod_inv(num,mod);

	return res%mod;
}


//二分探索
bool isOk(ll index, ll key,vector<ll> &a, bool g){
	if(g){
		if(a[index]<key){
			return true;
		}
	}
	else{
		if(a[index]>key){
			return true;
		}
	}
	return false;
}

ll bin_search(ll key, vector<ll> &a, bool g){
	
	ll l=-1;
	ll r=a.size();

	if(g){
		l=a.size();
		r=-1;
	}

	while(abs(r-l)>1){
		ll mid = (l+r)/2;
		if(isOk(mid, key, a, g)){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	return r;
}

int main(){

	ll n,d;
	cin>>n>>d;
	ll ans=0;

	ans=n/(2*d+1);

	if(n%(2*d+1)!=0){
		ans++;
	}

	cout<<ans<<endl;

	
	
    return 0;
}

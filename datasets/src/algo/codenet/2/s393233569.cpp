#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, a;

ll nibeki(ll q){
	ll r = 1;
	while(true){
		r *= 2;
		if(r > q){break;}
	}
	return r;
}

int main(){
	cin >> n;
	multiset<ll> mst;
	for(ll i = 0; i < n; i++){
		cin >> a;
		mst.insert(a);
	}
	
	ll ans = 0;
	while(!mst.empty()){
		auto itrend = mst.end();
		itrend--;
		a = *itrend;
		mst.erase(itrend);
		ll ia = nibeki(a)-a;
		if(mst.find(ia) != mst.end()){
			ans++;
			mst.erase(mst.find(ia));
		}
	}
	
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int n, k, mn;
	cin >> n >> k;
	set<int> d;
	rep(i, k){
		int in;
		cin >> in;
		d.insert(in);
	}
	rep(i, 10){
		if(d.count(i) == 0){
			mn = i;
			break;
		}
	}
	int ans = n;
	while(1){
		string sn = to_string(ans);
		// cerr << ans << endl;
		bool flag = true;
		rep(i, sn.size()){
			int now = sn[i] - '0';
			if(d.count(now) == 1){
				int newans = (now+1) * pow(10, (sn.size() - i - 1));
				rep2(j, i+1, sn.size()){
					newans += mn * pow(10, (sn.size() - j - 1));
				}
				ans = newans;
				flag = false;
				break;
			}
		}
		if(flag == true){
			cout << ans << endl;
			return 0;
		}
	}
	return 1;
}
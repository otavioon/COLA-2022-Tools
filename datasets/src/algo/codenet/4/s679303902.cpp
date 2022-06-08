#include <iostream> // cin, cout, cerr
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota
#include <cstdio> // printf, scanf
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <iomanip> // cout<<setprecision(n)
#include <functional> // function<void(int)>
#include <cmath>

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define ENDL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n,k;
	std::cin >> n >> k;
	std::set<int> set;
	rep(i,k) {
		int x;
		std::cin >> x;
		set.emplace(x);
	}
	for(int x=n;x<n*10;x++) {
		// check if all digits are not in set
		bool ok = true;
		int y = x;
		while(y) {
			if(set.count(y%10)) ok=false;
			y/=10;
		}
		if(ok) {
			print(x);
			break;
		}
	}
}

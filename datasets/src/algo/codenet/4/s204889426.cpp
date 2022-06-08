#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int mod = (int)1e9 + 7;
int n, m;
set<int> s;
int ok(int x) {
	while(x > 0) {
		if(!s.count(x % 10)) {
			return 0;
		}
		x/=10;
	}
	return 1;
}
int main () {
	for(int i = 0; i < 10; i++) {
		s.insert(i);
	}
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		s.erase(x);
	}
	for(int i = n; ; i++) {
		if(ok(i)) {
			cout << i << "\n";
			return 0;
		}
	}
 	return 0;
}


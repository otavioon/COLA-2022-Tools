
#include <bits/stdc++.h>
#define read(arr,n)	for(int i=0;i<n;i++) cin>>arr[i];
#define print(arr,n) for(int i=0;i<n;i++) cout << arr[i]<<' ';cout << endl;

using namespace std;

typedef long long ll;

void solve() {
	ll k, x;
	cin >> k >> x;
	if (500*k >= x) {
		cout <<"Yes\n";
	} else {
		cout << "No\n";
	}
}

int main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}

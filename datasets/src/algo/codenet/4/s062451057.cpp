//struct cmp {bool operator()(const pair<int, char> &a, const pair<int, char> &b) {if (a.first == b.first) {return a.second > b.second;} else {return a.first > b.first;}}};
#include<bits/stdc++.h>
#define endl "\n"
#define _  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define min_heap priority_queue <int, vector<int>, greater<int> >
#define max_heap priority_queue <int>
#define ll long long
//#define int long long
#define MOD 1000000007#define deb3(x,y,z) cout << #x << "=" << x << "\t"<<#y<<"="<<y<< "\t"<<#z<<"="<<z<<endl;
#define DEBUG cout<<"Hello1\n";
#define deb(x) cout << #x << " " << x << endl;
#define deb2(x,y) cout << #x << "=" << x << "\t\t"<<#y<<"="<<y<<endl;
#define deb3(x,y,z) cout << #x << "=" << x << "\t"<<#y<<"="<<y<< "\t"<<#z<<"="<<z<<endl;
#define all(v) (v).begin(),(v).end()
using namespace std;
vector<int> v;
int ans = INT_MAX;
int n, k;


void give(int curr) {

	for (auto x : v)
	{
		int val = curr * 10 + x;
		if (val >= n) {
			ans = min(ans, val);
		} else if (val != 0)
		{
			give(val);
		}
	}

}

void solve() {
	cin >> n >> k;
	set<int> ms;
	while (k--) {
		int x; cin >> x;
		ms.insert(x);
	}
	for (int i = 0; i <= 9; i++) {
		if (!ms.count(i)) {
			v.pb(i);
		}
	}

	give(0);

	cout << ans << endl;
}

int32_t main() {
	_


	solve();
}


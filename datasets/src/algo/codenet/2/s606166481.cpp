// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5, LG = 30;

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, ans = 0; cin >> n;
	multiset<int> st;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		st.insert(a);
	}
	while (sz(st) > 1) {
		int mx = * st.rbegin();
		st.erase(mx);
		int pw = 1;
		while (pw <= mx) pw *= 2;
		if (st.find(pw - mx) != st.end()) st.erase(pw - mx), ans++;
	}
	cout << ans << endl;


	return 0;
}

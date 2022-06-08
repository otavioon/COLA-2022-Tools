#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<functional>
#include<vector>
#include<map>

using namespace std;
#define endl '\n'
#define pb push_back
#define fst first
#define scd second
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define REP(i,n) for(int i = 0;i < (n);i++)
#define FOR(i,a,b) for(int i = (a);i <= (b);i++)
#define YES(n) cout << ((n) ? "YES" : "NO" ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No" ) << endl

constexpr int MOD = 1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

template <class T = int> T in() { T x; cin >> x; return (x); }
template <class T = int> void out(T x) { cout << (x) << endl; }

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

void solve() {

	int N;
	cin >> N;
	vi A(N + 1);
	vi B(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		B[i] = A[i] - i;
	}

	sort(B.begin() + 1, B.end());
	int b;
	b = B[N / 2];
	
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += abs(B[i] - b);
	}

	cout << ans << endl;

	return;

}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	solve();

	return 0;

}
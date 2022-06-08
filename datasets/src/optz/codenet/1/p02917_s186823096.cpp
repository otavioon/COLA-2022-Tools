
#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define str string

ll MOD = 1000000007, INFL = 1ll << 60, INF = 1 << 30, mod = 1e9 + 7, Max = INF, Min = -1;
ll a = 0, b = 0, c = 0, n = 0, sum = 0;
ll A[500000] = {}, B[500000] = {}, C[500000] = {}, dp[100][10] = {};
int dy[] = { 0, 0, 1, -1 }, dx[] = { 1, -1, 0, 0 };
vector <ll> v;
str S, T;
bool check = false, check2 = false;

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

int main() {

	//Code Line
	cin >> n;
	for (int i = 0; i < n-1; i++)cin >> A[i];


	if (n > 3) {
		for (int i = 0; i < n - 3; i++) {
			sum += min(A[i], A[i + 1]);
		}

		cout << sum + A[n - 3] + A[n - 2] << endl;
	}
if(n == 3)cout <<  A[n - 3]*2 + A[n-2]<< endl;
if (n == 2)cout << A[n - 2] * 2;
	return 0;
}

#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <functional>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define repv(i, v) for (unsigned (i)(0); (i)<(v.size()); ++(i))
#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define sortgi(v) sort(all(v), greater<int>())
#define sortgd(v) sort(all(v), greater<double>())
#define sortgll(v) sort(all(v), greater<ll>())
#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vd = vector<double>;
using vvd = vector<vd>;
using vs = vector<string>;
using ll = long long;
using pllll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using pqi = priority_queue<int>;
using pqd = priority_queue<double>;
using pqll = priority_queue<ll>;
using pqvi = priority_queue<vi>;
using pqvll = priority_queue<vll>;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	ll sum = 0;
	ll n = 0;
	vll A;
	ll b0 = 99999999999;
	ll b2 = -99999999999;
	rep(i, 0, N) {
		n += 1;
		ll a;
		cin >> a;
		a -= n;
		sum += a;
		b0 = min(b0, a);
		b2 = max(b2, a);
		A.push_back(a);
	}
	ll out0 = 0;
	repv(i, A) {
		out0 += ll(abs(A[i] - b0));
	}
	ll out2 = 0;
	repv(i, A) {
		out2 += ll(abs(A[i] - b2));
	}
	ll b1 = ll((b0 + b2) / 2);
	ll out1 = 0;
	repv(i, A) {
		out1 += ll(abs(A[i] - b1));
	}
	while(b0 - b1 > 1 || b2 - b1 > 1) {
		ll b01 = ll((b0 + b1) / 2);
		ll out01 = 0;
		repv(i, A) {
			out01 += ll(abs(A[i] - b01));
		}
		ll b12 = ll((b1 + b2) / 2);
		ll out12 = 0;
		repv(i, A) {
			out12 += ll(abs(A[i] - b12));
		}
		if (out01 < out12) {
			b2 = b1;
			b1 = b01;
			out2 = out1;
			out1 = out01;
		}
		else {
			b0 = b1;
			b1 = b12;
			out0 = out1;
			out1 = out12;
		}
	}
	ll out = min(out0, out1);
	out = min(out, out2);
	cout << out << endl;
}

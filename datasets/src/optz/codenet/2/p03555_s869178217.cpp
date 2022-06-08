#include<algorithm>
#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<utility>
#include<functional>
#include<cassert>
#include<cmath>
#include<math.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef vector<int> vint;
typedef vector<vint> vvint;
#define PI 3.1415926535;
#define MOD 1000000007;
vint t;
queue<ll> q;

int main(void) {
	ll k;
	cin >> k;
	t.resize(k, (int)1e6);
	q.push(1);
	t[1] = 1;

	while (!q.empty()) {
		ll x = q.front(); q.pop();
		if (t[(x + 1)%k] > t[x] + 1) {
			q.push(x + 1);
			t[(x + 1)%k] = t[x] + 1;
		}
		if (t[(x * 10) % k] > t[x]) {
			q.push((x * 10) % k);
			t[(x * 10) % k] = t[x];

		}

	}
	cout << t[0] << endl;
	return 0;
}
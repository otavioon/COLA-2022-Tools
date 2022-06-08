#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using LL = long long;

void calc(vector<vector<LL>> &R, vector<LL> &ans, vector<LL>& value, LL i ,LL bef) {
	ans[i] += value[i] + bef;
	bef = value[i] + bef;
	for (LL j = 0; j < R[i].size(); j++) {
		LL padd = R[i][j];
		
		calc(R, ans, value, padd, bef);

	}
	return;
}

void add(vector<vector<LL>>& R, vector<LL>& value,LL p, LL x){
	value[p] += x;
}

int main() {
	LL N, Q;
	cin >> N >> Q;
	vector<vector<LL>> R(N + 1);
	for (LL i = 1; i < N; i++) {
		LL a, b;
		cin >> a >> b;
		R[a].push_back(b);
	}
	vector<LL> p(Q + 1), x(Q + 1);
	for (LL i = 1; i <= Q; i++) {
		cin >> p[i] >> x[i];

	}
	vector<LL> ans(N + 1, 0);
	vector<LL> value(N + 1, 0);
	LL i = 1;
	for (LL q = 1; q <= Q; q++) {
		LL padd = p[q];
		add(R, value, padd, x[q]);
	}

	calc(R, ans, value, 1, 0);

	for (LL i = 1; i <= N; i++) {
		cout << ans[i];
		if (i != N) {
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}



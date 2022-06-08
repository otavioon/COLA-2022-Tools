#include "bits/stdc++.h"

using namespace std;

void solve()
{
	int N;
	cin >> N;
	vector<long> powers;
	multiset<long> as;
	for (int i = 0; i < N; i++)
	{
		long a;
		cin >> a;
		as.insert(a);
	}
	long t = 1;
	while(t <= 2*1e9) powers.push_back(t), t*=2;
	//reverse(powers.begin(), powers.end());
	long ans = 0;
	for (long p : powers)
	{
		for (auto i = as.end(); i != as.begin(); advance(i, -1))
		{
			auto j = as.find(p - *i);
			if (j == as.end() || i == j) continue;
			ans++;
			as.erase(*i);
			as.erase(*j);
		}
	}
	cout << ans << endl;
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}

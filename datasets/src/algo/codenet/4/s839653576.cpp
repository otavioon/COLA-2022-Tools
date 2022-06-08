#include<bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
typedef long long ll;
ll GCD(ll x, ll y) { return y ? GCD(y, x%y) : x; }
ll LCM(ll x, ll y) { return x * y / GCD(x, y); }

using namespace std;
int main() {
	int n,k;
	cin >> n >> k;

	vector<int> d(k);
	for (int i = 0; i < k; i++)
	{
		cin >> d[i];
	}

	int ans = n;

	bool flag = false;

	for (int i = n;i < 9999990; i++)
	{
		int tmp = i;
		set<int> s;
		
		while (tmp != 0) {
			s.insert(tmp % 10);
			tmp /= 10;
		}

		flag = true;
		for (int dx : d)
		{
			if (s.count(dx)) {
				
				flag = false;
				
			}

		}

		if (flag) {
			cout << i;
			break;
		}

		
	}




}
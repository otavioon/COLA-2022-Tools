#include <bits/stdc++.h>

using namespace std;

set<int> s;

bool check(int n)
{
	while (n > 0)
	{
		if (!s.count(n % 10))
			return false;
		n /= 10;
	}

	return true;
}

signed main()
{
	int n, k, temp;
	cin >> n >> k;
	for (int i = 0; i  < 10; i++)
		s.insert(i);

	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		s.erase(temp);
	}

	while (!check(n))
		n++;
	cout << n << endl;

	return 0;
}

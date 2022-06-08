#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	set<int> d;
	for (int i = 0; i < k; i++)
	{
		int di;
		cin >> di;
		d.insert(di);
	}
	for (int i = n; i < 100*n; i++)
	{
		bool valid = true;
		for (int j = i; j > 0; j /= 10)
		{
			if (d.find(j%10) != d.end())
			{
				valid = false;
				break;
			}
		}
		if (valid)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}

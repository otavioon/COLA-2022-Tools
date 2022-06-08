#include <cstdio>
#include <set>
int main()
{
	// freopen("AGC029-B.in", "r", stdin);
	std::multiset<int> se;
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		se.insert(x);
	}
	while (!se.empty())
	{
		int x = *se.rbegin(), mx = 0;
		se.erase(se.find(x));
		for (int i = 0; i < 30; i++)
		{
			if (x & (1 << i))
				mx = i;
		}
		int y = (1 << mx + 1) - x;
		if (se.find(y) != se.end())
		{
			ans++;
			se.erase(se.find(y));
		}
	}
	printf("%d\n", ans);
	return 0;
}

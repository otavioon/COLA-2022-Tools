#include<bits/stdc++.h>
#define maxn 200010
using namespace std;
int val[maxn];
multiset<int> S;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
		S.insert(val[i]);
	}
	int res = 0;
	while (!S.empty())
	{
		multiset<int>::iterator it = S.end();
		it--;
		int tmp = *it, need = 1;
		S.erase(S.find(tmp));
		while (need <= tmp) need *= 2;
		if (S.find(need - tmp) != S.end())
		{
			res++;
			S.erase(S.find(need - tmp));
		}
	}
	printf("%d\n", res);
	return 0;
}
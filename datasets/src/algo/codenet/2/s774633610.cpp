#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
multiset<int, greater<int> > s;
int a[maxn];
int n, ans;
int main() 
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%d", &a[i]);
		s.insert(a[i]);
	}
	for(auto it = s.begin(); it != s.end(); )
	{
		bool f = 0;
		for(int i = 30; i; --i)
		{
			if(s.count((1 << i) - *it) > (*it == (1 << i) - *it))
			{
				s.erase(s.find((1 << i) - *it));
				s.erase(it++);
				++ans;
				f = 1;
				break;
			}
		}
		if(!f) ++it;
	}
	printf("%d\n", ans);
	return 0;
}
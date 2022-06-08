#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull jc[46], n, i, k;
multiset<ull> v;
void init()
{
	jc[0] = 1;
	for (int i = 1; i < 46; i ++) jc[i] = jc[i - 1] * 2;
}
int main() 
{
	init();
	cin >> n;
	ull ans = 0;
	for (i = 0; i < n; i ++) cin >> k, v.insert(k);
	multiset<ull>::iterator iter;
	while (!v.empty())
	{
		iter = v.end();
		iter --;
		ull sum = *iter;
		v.erase(iter);
		for (i = 0; jc[i] <= sum; i ++);
		if (v.find(jc[i] - sum) != v.end())
		{
			ans ++;
			v.erase(v.find(jc[i] - sum));
		}
	}
	cout << ans << endl;
}
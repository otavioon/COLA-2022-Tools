#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <functional>

using namespace std;
static const int INF = 1e9;
typedef pair<int, int> P;

void solve()
{
	int N, K;
	cin >> N >> K;
	set<int> D;
	for (int i = 0; i < K; ++i)
	{
		int d;
		cin >> d;
		D.insert(d);
	}
	int ans = 1;
	while (true)
	{
		int temp = ans;
		bool isOK = true;
		while (temp)
		{
			if (D.find(temp % 10) != D.end())
			{
				isOK = false;
				break;
			}
			temp /= 10;
		}
		if (isOK && ans >= N)
		{
			break;
		}
		++ans;
	}
	cout << ans << endl;
}

int main()
{
	solve();
	return(0);
}
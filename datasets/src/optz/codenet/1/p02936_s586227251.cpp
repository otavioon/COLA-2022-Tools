#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

ll parent[200004];
ll counter[200004];
ll calced_counter[200004];

ll dfs(int node)
{
	if (node == 0)
	{
		return 0;
	}

	if (calced_counter[node] > 0)
	{
		return calced_counter[node];
	}

	return calced_counter[node] = counter[node] + dfs(parent[node]);
}

void solve()
{
	fill(parent, parent + 200004, -1);
	fill(counter, counter + 200004, 0);
	fill(calced_counter, calced_counter + 200004, 0);

	ll n, q, a, b, p, x;
	cin >> n >> q;

	parent[1] = 0;
	for(ll i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		if (parent[a] == -1)
		{
			parent[a] = b;
		}
		else
		{
			parent[b] = a;
		}
	}

	for(ll i = 0; i < q; ++i)
	{
		cin >> p >> x;
		counter[p] += x;
	}


	//* test input
	n = 200000; q = 200000;
	for(int i = 1; i <= n; ++i)
	{
		parent[i + 1] = i;
	}

	for(ll i = 1; i <= q; ++i)
	{
		counter[i + 1] += 10000LL;
	}
	// test input
	//*/


	for(int i = 1; i <= n; ++i)
	{
		dfs(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << calced_counter[i] << endl;
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}
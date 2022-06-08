#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1000000007;
const int MAX_V = 201;
ll dp[2][4];
int now = 0;
int t[3];
ll p2[32];
void Powersoftwo() {
	int n;
	cin >> n;
	ll a[200010];
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	p2[0] = 2;
	for (size_t i = 1; i < 32; i++)
	{
		p2[i] = p2[i - 1] * 2;
	}
	ll res = 0;

	for (int i = 31; i >= 0; i--)
	{
		for (int k= 0,j = n - 1; k < n; k++)
		{
			if (a[k] != -1) {
				while (k < j && (a[j] == -1 || a[k] + a[j] > p2[i])) j--;
				if (k < j && a[j] != -1 && a[k] + a[j] == p2[i]) {
					res++;
					a[k] = a[j] = -1;
				}
				
			}
		}
	}
	cout << res << endl;
}
int main() {
	Powersoftwo();
	return 0;
}


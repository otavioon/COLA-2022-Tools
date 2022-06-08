#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const double pi = acos(-1);
const int maxn = 2e6 + 10;
const double eps = 1e-8;
const ll mod = 1e9 + 7;
const ull base = 131;
const ull mod1 = 1e9 + 9;
const ull mod2 = 1610612741;

set<char> st;
set<char>::iterator it;
char s[maxn];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	while (k--)
	{
		int x;
		scanf("%d", &x);
		st.insert(x+'0');
	}
	for (int i = n; 1; ++i)
	{
		sprintf(s, "%d", i);
		bool flag = true;
		for (int j = 0; s[j]; ++j)
			if (st.find(s[j]) != st.end()) flag = false;
		if (flag) 
		{
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
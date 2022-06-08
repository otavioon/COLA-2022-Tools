#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <functional>
//#include <unordered_set>
#define INF 2147483647
#define MAXN  100005
#define mod 1000000007
#define PII pair<int, int>
#define lowbit(x) (x&-x)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef local_debug1
	ifstream inputs("input.txt");
	cin.rdbuf(inputs.rdbuf());
	freopen("input.txt", "r", stdin);
#endif

	int d, sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> d;
		sum += d;
	}
	if (sum % 3 == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=int(1e5 + 5);
int arr[maxn];
set<int>S;
int main()
{
	S.clear(); int sizes = 0;
	int n; cin >> n;
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
	int tmp = 1;
	int ans = 0,k=1;
	while (1) {
		 tmp = arr[tmp];
		 if (tmp == 2) { ans = k; break; }
		 S.insert(tmp); sizes++;
		 if (S.size() < sizes) { ans = -1; break; }
		 k++;
	}
	cout << ans;
	return 0;
}
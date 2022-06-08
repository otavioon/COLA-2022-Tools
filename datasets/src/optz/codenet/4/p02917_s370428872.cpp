#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <set>
#include <deque> 
#include <string>


using namespace std;

int n;

int a[110];
int b[110];

int main()
{
	scanf("%d", &n);
	
	for (int i = 1 ; i <= n - 1 ; i++)
		scanf("%d", &(b[i]));

	a[1] = b[1];
	for (int i = 2 ; i <= n - 1 ; i++)
	{
		a[i] = b[i - 1];
		if (a[i] > b[i])
			a[i] = b[i];
	}
	a[n] = b[n - 1];
	
	int ans = 0;
	for (int i = 1 ; i <= n ; i++)
		ans = ans + a[i];
		
		
	printf("%d\n", ans);
		
	return 0;
}

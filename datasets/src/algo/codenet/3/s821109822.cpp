#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAXN 100010
int a[MAXN], b[MAXN], c[MAXN];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &c[i]);
	}
	sort(a, a + N);
	sort(b, b + N);
	sort(c, c + N);
	long long ai=0, ci=0;
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		while (a[ai] < b[i] && ai< N)
		{
			ai++;
		}
		while (c[ci] <= b[i] && ci<N)
		{
			ci++;
		}
		sum += ai*(N-ci);
	}
	printf("%lld\n", sum);
	return 0;
}

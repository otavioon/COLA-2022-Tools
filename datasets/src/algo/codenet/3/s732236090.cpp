#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;
const int MAX = 1e5+10;
LL N;
LL a[MAX], b[MAX], c[MAX];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> a[i];
	for (int i = 1; i <= N; i++)
		cin >> b[i];
	for (int i = 1; i <= N; i++)
		cin >> c[i];
	sort(a + 1, a + 1 + N), sort(b + 1, b + 1 + N), sort(c + 1, c + 1 + N);

	LL sum = 0;
	LL ai = 0, ci = 0;
	for (int i = 1; i <= N; i++) 
	{
		while (a[ai + 1]<b[i] && ai + 1 <= N)
			ai++;
		while (c[ci + 1] <=b[i] && ci + 1 <= N)
			ci++;
		sum += ai * (N-ci);
	}

	cout << sum << endl;

	return 0;
}
#include <bits/stdc++.h>
#define MAX 123
using namespace std;

char str[MAX];

int main(void)
{
	int K;
	cin >> str >> K;
	long long ans = 0;
	int N = strlen(str);
	int idx = 0;
	while (str[0] == str[idx] && idx < N) idx++;
	if (idx == N)
	{
		long long NN = 1LL * N * K;
		cout << NN / 2 << endl;
		return 0;
	}
	int ridx = N - 1;
	while (str[0] == str[ridx]) ridx--;
	for (int i = idx; i < ridx; i++)
	{
		if (str[i] == str[i - 1])
		{
			ans += K;
			str[i] = 0;
		}
	}
	ans += idx / 2;
	ans += (N - 1 - ridx) / 2;
	ans += (1LL * (N - 1 - ridx + idx) / 2) * (K - 1);
	cout << ans << endl;
	return 0;
}

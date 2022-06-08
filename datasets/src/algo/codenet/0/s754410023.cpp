#include<bits/stdc++.h>
using namespace std;
string S;
long long K, ans;
int L, R;
int main(void)
{
	cin >> S >> K;
	if (S[0] == S[S.length() - 1])
	{
		for (int i = 1; i < S.length(); i++)
		{
			if (S[i] != S[i - 1])
			{
				L = i;
				break;
			}
		}
		if (L)
		{
			for (int i = S.length() - 1; i >= 0; i--)
			{
				if (S[i] != S[i - 1])
				{
					R = i;
					break;
				}
			}
			for (int i = L; i < R; i++)
			{
				if (S[i] == S[i - 1])
				{
					ans++;
					i++;
				}
			}
			cout << ans * K + (L + S.length() - R) / 2 * (K - 1);
		}
		else
		{
			cout << S.length() * K / 2 << endl;
		}
	}
	else
	{
		for (int i = 1; i < S.length(); i++)
		{
			if (S[i] == S[i - 1])
			{
				ans++;
				i++;
			}
		}
		cout << ans * K << endl;
	}
	return 0;
}
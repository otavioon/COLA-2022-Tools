#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define ALL(a) (a).begin(),(a).end()
#define MOD 1e9+7
typedef long long ll;
using namespace std;

int main()
{
	string s;
	ll k;
	cin >> s >> k;
	int i = 0;
	ll ans = 0;
	bool flag = false;
	if (s.size() == 1) ans = k / 2;
	else if (s.size() == 2)	ans = s[0] == s[1] ? k : 0;
	else 
	{
		while (i < s.size())
		{
			if (i < s.size() - 1)
			{
				if (s[i + 1] == s[i])
				{
					ans++;
					if(i==0)flag = true;
					i += 2;
				}
				else i++;
			}
			else
			{
				if (s[i] == s[0])
				{
					if (!flag)ans++;
					flag = true;
				}
				i++;
			}
		}
		ans *= k;
		if (flag)ans--;
	}
	co(ans);
	return 0;
}

#include <bits/stdc++.h>
 
using namespace std;

unordered_map <int,int> cnt;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	long long int t;
	int res = 0;
	vector <long long int> v;
	vector <long long int> two;
	long long int val = 1;

	while(val < 1e9)
	{
		two.push_back(val);
		val*=2;
	}

	sort(two.begin(),two.end());

	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> t;
		v.push_back(t);
		cnt[t]++;
	}

	sort(v.begin(),v.end());

	for(int i=0;i<two.size();i++)
	{
		for(int j=0;j<n;j++)
		{
			if(cnt[v[j]]==0)
			{
				continue;
			}
			long long int val = two[i] - v[j];
			if(val<=0)
			{
				continue;
			}
			if(cnt[val] > 0)
			{
				if(val==v[j] && cnt[v[j]]==1)
				{
					continue;
				}
				cnt[val]-=1;
				cnt[v[j]]-=1;
				res++;
			}
		}
	}

	cout << res << '\n';

	return 0;	
}

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a(2000000);


int main(int argc, char **argv)
{
	cin >> N;
	for (int i = 1; i < N+1; ++i) cin >> a[i];

	int ans;
	int target = 1;
	vector<int> t_vec;
	while (true)
	{
		for (int i = 1; i < N+1; ++i)
		{
			if (target == i)
			{
				auto result = find(t_vec.begin(), t_vec.end(), a[i]);
				if (result != t_vec.end())
				{
					ans = -1;
					goto exit;
				}
				target = a[i];
				t_vec.push_back(a[i]);
			}

			if (target == 2)
			{
				ans = t_vec.size();
				goto exit;
			}
		}
	}

 exit:
	std::cout << ans << std::endl;
}

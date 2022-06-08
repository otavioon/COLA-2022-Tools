#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <functional>

#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<bool> digit_list(10, false);

	for (int i = 0; i < K; i++)
	{
		int d;
		cin >> d;
		digit_list[d] = true;
	}

	int val = N;
	while (true)
	{
		string nstr = to_string(val);

		bool check = true;
		for (int i = 0; i < nstr.size(); i++)
		{
			for (int j = 0; j < digit_list.size(); j++)
			{
				if (digit_list[j] && (nstr[i] - '0') == j)
				{
					check = false;
					break;
				}
			}

			if (!check) break;
		}

		if (check)
		{
			cout << val;
			break;
		}

		val++;
	}
	
	return 0;
}
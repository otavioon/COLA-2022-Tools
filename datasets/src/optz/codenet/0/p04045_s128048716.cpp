#include "bits/stdc++.h"
 
template<typename T>
T get_value(std::istream& is);
 
 
int getMinNum_div(int _nOriginal, const std::vector<int>& _avoid)
{
	for (int i = _nOriginal; i < 100000; i++)
	{
		bool bFound = false;
		int c, d;
 
		c = i;
		while (c > 0 && !bFound)
		{
			div_t dv = div(c, 10);
			if (std::binary_search(_avoid.cbegin(), _avoid.cend(), dv.rem))
			{
				bFound = true;
				break;
			}
 
			c = dv.quot;
		}
		
		if (!bFound) return i;
	}
 
	return -1;
}
 
 
 
 
int main()
{
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
 
	int N, K;
 
	std::cin >> N >> K;
	std::vector<int> v(K);
 
	for (auto& e : v) {
		std::cin >> e;
	}
 
	int answer = getMinNum_div(N, v);
	std::cout << answer << std::endl;
 
	return 0;
};
 
 
template<typename T>
inline T get_value(std::istream& is)
{
	T v;
	is >> v;
	return v;
}
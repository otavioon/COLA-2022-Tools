
#include "bits/stdc++.h"

template<typename T>
T get_value(std::istream& is);

int getMinNum_recursive(int _nOriginal, const std::set<char>& _avoid)
{
	std::string org = std::to_string(_nOriginal);
	for (auto& c : org)
	{
		if (_avoid.find(c) != _avoid.end())
		{
			return getMinNum_recursive(_nOriginal + 1, _avoid);
		}
	}

	return _nOriginal;
}


int getMinNum_bsearch_recursive(int _nOriginal, const std::vector<char>& _avoid)
{
	std::string org = std::to_string(_nOriginal);
	for (auto& c : org)
	{
		if (std::binary_search(_avoid.cbegin(), _avoid.cend(), c))
		{
			return getMinNum_bsearch_recursive(_nOriginal + 1, _avoid);
		}
	}

	return _nOriginal;
}

int getMinNum_bsearch(int _nOriginal, const std::vector<char>& _avoid)
{
	for (int i = _nOriginal; i < 10000; i++)
	{
		std::string strNum = std::to_string(i);
		bool bFound = false;
		for (auto& c : strNum)
		{
			if (std::binary_search(_avoid.cbegin(), _avoid.cend(), c))
			{
				bFound = true;
				break;
			}
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
	std::vector<char> v(K);
	//std::set<char> s;

	for (auto& e : v) {
		std::cin >> e;
		//s.insert(e);
	}

	//int answer = getMinNum(N, s);
	//int answer = getMinNum_bsearch(N, v);
	int answer = getMinNum_bsearch(N, v);
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

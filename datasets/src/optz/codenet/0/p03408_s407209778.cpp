#include <iostream>
#include <algorithm>
#include <string>

std::string strArr[105];
int count[105];
int n, m;

int findString(std::string str)
{
	for (int i = 0; i < n; i++)
	{
		if (strArr[i] == str)
			return i;
	}
	return -1;
}
int main()
{
	std::cin >> n;
	int ind = 0;
	for (int i = 0; i < n; i++)
	{
		std::string t;
		std::cin >> t;
		if (findString(t) == -1)
		{
			count[ind] = 1;
			strArr[ind++] = t;
		}
		else
			count[findString(t)]++;
	}
	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		std::string t;
		std::cin >> t;
		if (findString(t) == -1)
			;
		else
			count[findString(t)]--;
	}
	int max = count[0];
	for (int i = 0; i < n; i++)
	{
		if (count[i] > max)
			max = count[i];
	}
	std::cout << ((max > 0) ? max : 0);
	return 0;
}
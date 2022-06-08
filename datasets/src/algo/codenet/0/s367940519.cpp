#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
using namespace std;

int main()
{
	unsigned long long int p = 0;
	unsigned long long int k;
	string s;

	cin >> s >> k;
	for (int i = 0;i < s.length();)
	{
		if (s[i] != s[i + 1])
		{
			i++;
		}
		else if (s[i] == s[i + 1])
		{
			p++;
			i += 2;
		}

	}
	if (s[0] == s[s.length() - 1] && s[s.length() - 2] != s[s.length() - 1])
		p++;
	cout << p * k;

	return 0;
}
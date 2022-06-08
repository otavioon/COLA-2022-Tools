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
	long long int p = 0;
	long long int k;
	int flag = 0;
	int fin = 0;
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
			if (i + 1 == s.length() - 1)
				fin = 1;
			p++;
			i += 2;
		}

	}
	if (k > 1)
	{
		if (fin==0 && s[0] == s[s.length() - 1])
		{
			p++;
			flag = 1;
		}
		if (flag == 1)
			cout << p * k - 1;
		else
			cout << p * k;
	}
	else
		cout << p * k;

	return 0;
}
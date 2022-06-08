#include <bits/stdc++.h>

using namespace std;

int main()
{
	int length;
	string s;
	cin >> s;
	bool checked = false;
	length = s.size();
	unsigned long long k;
	cin >> k;
	// i

	unsigned long long changes = 0, lastChange = -1;


	if (length > 1)
		if (s[0] == s[1] && s[0] == s[length - 1])
		{
			lastChange = 0;
			changes++;
			checked = true;
		}

	for (int i = 1; i < length; i++)
	{
		if (s[i] == s[i-1])
		{
			if (lastChange == i-1)
				continue;
			else
			{
				lastChange = i;
				changes++;
			}
		}
		else
			continue;
	}
	int lastlastChange = -1;
	unsigned long long newChanges = 0;


	if (k > 0 && length > 1 && !checked && s[0] == s[length - 1])
		{
			changes++;
		}

	if (length == 1)
		{
			cout << ceil((double)k/2);
			return 0;
		}



	if (lastChange == length-1)
	{
	for (int i = 0; i < length; i++)
		{
			if (s[i] == s[i-1])
			{
				if (lastlastChange == i-1)
					continue;
				else
				{
					lastlastChange = i;
					newChanges++;
				}
			}
			else
				continue;
		}

	if (k > 0)
	{
		if (k % 2 == 0)
				{
					cout << (changes * (k/2) + newChanges * (k/2));
					return 0;
				}
				else
				{
					cout << (changes * ((int)k/2 + 1) + newChanges * ((int)k/2));
					return 0;
				}
		}
	}







	if (k > 0)
	{
		cout << changes *k;
		return 0;
	}
	cout << changes;
}

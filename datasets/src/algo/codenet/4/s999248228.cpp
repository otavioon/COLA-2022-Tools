#define _CRT_SECURE_NO_WARNINGS
#pragma _attribute_((optimize("-O2")))

#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <cstdio>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include <time.h>
#include <iomanip>

//#define Local

using namespace std;

set<int> dis;

bool chs(int in)
{
	bool flag = 1;
	while(flag&&in>0)
	{
		int tmp = in % 10;
		in /= 10;
		if (dis.count(tmp) != 0)
			flag = 0;
	}
	return flag;
}

int main()

{

	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input1.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);

	int t, k;
	while(cin>>t>>k)
	{
		dis.clear();
		while(k--)
		{
			int tmp;
			cin >> tmp;
			dis.insert(tmp);
		}
		while(1)
		{
			if(chs(t))
			{
				cout << t << endl;
				break;
			}
			t++;
		}
	}

#ifdef Local
	cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
#endif
	return 0;
}
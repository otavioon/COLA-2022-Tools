#include <bits/stdc++.h>
using namespace std;

int main()
{
	int c[9];
	bool flag = true;
	for (int i = 0; i < 9; ++i) cin >> c[i];
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (!(c[i]+c[i+3*j+1] == c[i+1]+c[i+3*j]))
			{
				flag = false;
			}
		}
	}
	if(flag){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
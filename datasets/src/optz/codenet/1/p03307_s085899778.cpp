#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(long long i=1;i<=10000000000;i++)
	{
		if(2*n==i)
		{
			cout<<i;
			break;
		}
	}
	return 0;
}

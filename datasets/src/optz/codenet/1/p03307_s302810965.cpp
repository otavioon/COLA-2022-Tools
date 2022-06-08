#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,x;
	cin>>N;
	int bandera=0;
	x=N;
	while(bandera!=1)
	{
		if(x%2==0 && x%N==0)bandera =1;
		else
		{
			x*=2;
		}
	}
	cout<<x<<"\n";
	return 0;
}

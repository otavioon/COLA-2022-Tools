#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a,sum=0;
	for(int i=1;i<=9;i++)
	{
		cin>>a;
		sum+=a;
	}
	if(sum%3==0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;	
	return 0;
}
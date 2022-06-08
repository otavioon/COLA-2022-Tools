//广度优先搜索,BFS
#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;
ll n,i;
int main()
{
	
	cin>>n;
	int tag=0,x,s=0;
	for(i=sqrt(n);i<=n;i++)
	{
		if(n%i==0)
		{
			x=i;
			break;
		}
	}
	while(x)
	{
		x/=10;
		s++;
	}
	cout<<s<<endl;
}
#include<iostream>
#include<algorithm>
#define N 10000
#define K 10
using namespace std;
int k,d,n,ans=100000000;
bool m[K+2];
void dfs(int res)
{
	if(res>=n && res<ans)
	{
		ans=res;
		return ;
	}
	if(res>=n) return ;
	for(int i=9;i>=0;i--)
		if(!m[i]) dfs(res*10+i);
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>d,m[d]=1;
	for(int i=1;i<10;i++)
		if(!m[i]) dfs(i);
	cout<<ans;
}

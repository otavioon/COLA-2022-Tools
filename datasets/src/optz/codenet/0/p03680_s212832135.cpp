#include<iostream>
#include<utility>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
int mark[100005],a[100005];
int main()
{
	int N,i,x=1,cnt=0;
	cin>>N;
	for(i=1;i<=N;i++)
	cin>>a[i];
	while(mark[2]==0&&cnt<=N)
	{
		x=a[x];
		mark[x]++;
		cnt++;
	}
	if(!mark[2])
	cout<<-1<<endl;
	else
	cout<<cnt<<endl; 
	return 0;
}

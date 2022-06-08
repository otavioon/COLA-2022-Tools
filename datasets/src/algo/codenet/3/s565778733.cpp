#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long N,t=0;
	cin>>N;
	long long a[N],b[N],c[N];
	for(int i=0;i<N;i++)
	cin>>a[i];
	sort(a,a+N);
	for(int i=0;i<N;i++)
	cin>>b[i];
	sort(b,b+N);
	for(int i=0;i<N;i++)
	cin>>c[i];
	sort(c,c+N);
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
	for(int m=0;m<N;m++)
	{
		if(c[m]>b[j]&&b[j]>a[i])
		t++;
		else
		continue;
	}
	if(b[j]<a[i])
	continue;
	}
	
	printf("%d\n",t);
	return 0;
}
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,a;
int main()
{
	scanf("%d%d",&n,&a);
	a=a*2+1;
	if(n%a) a=n/a+1;
	else a=n/a;
	printf("%d\n",a);
	return 0;
} 
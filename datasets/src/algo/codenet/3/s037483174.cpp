#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100005],b[100005],c[100005],d[100005],e[100005];
int main()
{
	int n,i,j,l,k,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
		for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		sort(c+1,c+n+1);
		k=0;
		for(i=1;i<=n;i++)
		{k=0;
			for(j=1;j<=n;j++)
			{k=0;
				for(l=1;l<=n;l++)
				{
					if(a[i]<b[j]&&b[j]<c[l])
					{
						sum+=n-l+1;
						//printf("%d %d %d **%d\n",a[i],b[j],c[l],sum);
						k=1;
						break;
					}
					
				}
				//if(k)break;
			}
		}
		printf("%d\n",sum);
	}
}
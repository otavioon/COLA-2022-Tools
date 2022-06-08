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
				
		for(k=1,l=1;k<=n&&l<=n;)
		{
			if(b[k]<c[l])
			{
				e[k]=l;
				k++;
			}			
			else
			l++;
		}
		//for(i=1;i<=n;i++)
		//printf("%d ",e[i]);
		//printf("\n");
	//	k=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i]<b[j])
				{
					sum+=n-e[j]+1;
					
					//printf("k=%d sum=%d*\n",k,sum);
				}
				
			}						
		}
		
		printf("%d\n",sum);
	}
}
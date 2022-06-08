#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100005],b[100005],c[100005];
int main()
{
	int n,i,j,l,k,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		scanf("%d",&b[i]);
		for(i=0;i<n;i++)
		scanf("%d",&c[i]);
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);
		j=0;k=0;				
		for(i=0;i<n;i++)
		{
			while(a[j]<b[i]&&j<n){
				j++;
			}
			while(b[i]>=c[k]&&k<n){
				k++;
			}
			sum+=j*(n-k);
		}			
		printf("%d\n",sum);
	}
}
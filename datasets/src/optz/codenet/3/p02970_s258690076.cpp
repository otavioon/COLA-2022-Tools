#include<cstdio>

int n,d,i,j,vis[21],last,ans,sum;

int main()
{
	scanf("%d%d",&n,&d);
	sum=n;
	while(i<n)
	{
		if(vis[i])
		{
			i++;
			continue;
		}
		if(i-last==d)
		{
			for(j=last;j<=i+d;j++)
				vis[j]=1,sum--;
			ans++;
			last=i+d+1;
		}
		i++;
	}
	if(sum>0)ans++;
	printf("%d",ans);
	return 0;
}

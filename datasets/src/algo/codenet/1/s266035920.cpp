#include<stdio.h>
int main()
{
	int i,j;
	int x[3][3];
	int sum[6];
	for(i=0;i<3;i++)
	{
		scanf("%d%d%d",&x[i][0],&x[i][1],&x[i][2]);
	}
	sum[0]=x[0][0]+x[1][1]+x[2][2];
	sum[1]=x[1][0]+x[2][1]+x[0][2];
	sum[2]=x[2][0]+x[0][1]+x[1][2];
	sum[3]=x[0][2]+x[1][1]+x[2][0];
	sum[4]=x[1][2]+x[2][1]+x[0][0];
	sum[5]=x[2][2]+x[0][1]+x[1][0];
	if(sum[0]==sum[1]&&sum[1]==sum[2]&&sum[2]==sum[3]&&sum[3]==sum[4]&&sum[4]==sum[5]) printf("Yes\n");
	else printf("No\n");
}
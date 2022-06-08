#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
const int MaxN = 1e5;

int main()
{
	int c[5][5];
	int vis = 0,a1,a2,a3,b1,b2,b3;
	for(int i = 1;i <= 3;i++)
		for(int j = 1;j <= 3;j++)
			scanf("%d",&c[i][j]);
	for(int i = 0;i <= MaxN;i++)
	{
		a1 = i;
		b1 = c[1][1]-a1;
		b2 = c[1][2]-a1;
		b3 = c[1][3]-a1;
		a2 = c[2][1]-b1;
		a3 = c[3][1]-b1;
		if(c[2][2]==b2+a2&&c[3][3] == b3+a3&&c[2][3]==a2+b3&&c[3][2]==a3+b2)
		{
			vis = 1;
			break;
		}
	}
	if(vis==1) printf("Yes\n");
	else printf("No\n");
	return 0;
}
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int mmap[3][3];

int main()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			scanf("%d",&mmap[i][j]);
	}
	int sum1,sum2,sum3,sum4;
	sum1=mmap[0][0]+mmap[1][1]+mmap[2][2];
//	sum2=mmap[2][0]+mmap[1][1]+mmap[0][2];
	sum2=mmap[0][1]+mmap[1][2]+mmap[2][0];
	sum3=mmap[1][0]+mmap[2][1]+mmap[0][2];
	if(sum1==sum2&&sum2==sum3)
		printf("Yes\n");
	else printf("No\n");
}
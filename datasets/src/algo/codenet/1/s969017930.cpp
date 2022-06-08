#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int shu[5][5];

int main()
{
	int flag = 0;
	int a1, a2, a3, b1, b2, b3;
	a1 = a2 = a3 = b1 = b2 = b3 = 0;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
		{
			scanf("%d", &shu[i][j]);
		}
	for(int i = 1; i <= 10000000; i++)
	{
		a1 = i;
		b1 = shu[1][1] - a1;
		b2 = shu[1][2] - a1;
		b3 = shu[1][3] - a1;
		a2 = shu[2][1] - b1;
		a3 = shu[3][1] - b1;
		if(b2 + a2 == shu[2][2] && a2 + b3 == shu[2][3] && a3 + b2 == shu[3][2] && a3 + b3 == shu[3][3]) {
			flag = 1;
			break;
		}
	}
	if(flag == 1) printf("Yes\n");
	else printf("No\n");
}
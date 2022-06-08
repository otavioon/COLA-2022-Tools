#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;

int c[10][10];
int main()
{
	int sum = 0;
	for(int i=1;i<=3;i++)
		for (int j = 1;j <= 3;j++)
		{
			scanf("%d", &c[i][j]);
			sum += c[i][j];
		}
	if (sum % 3)
	{
		puts("No");
		return 0;
	}
	//for(int )
	puts("Yes");
}
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<set>
#include<queue>
#include<string>
#include<sstream>
#include<iostream>
#include<sstream>
#include<stack>
#include<map>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int f[200];
char a[100],b[100];
int main()
{
	int k;
	scanf("%s %d", a+1, &k);
	for (int i = 0; i < k; i++)
	{
		getchar();
		char t;
		scanf("%c", &t);
		f[t] = 1;
	}
	a[0] = '0';
	int flag = 0, flag2 = 0, flag3 = 0;
	for (int i = 1; a[i] != '\0'; )
	{
		if (flag == 0)
		{
			while (f[a[i]] == 1)
			{
				flag = 1;
				a[i]++;
				if (a[i] > '9') 
				{ 
					a[i - 1]++;
					flag3=1;
					if (i == 1)flag2++; 
					i --;
					flag = 0;
					continue;
				}
			}
			i++;
		}
		else
		{
			a[i] = '0';
			while (f[a[i]] == 1)
			{
				a[i]++;
			}
			i++;
		}
		if (flag3 == 1)
		{
			flag3 = 0;
			flag = 1;
		}
	}
	if(flag2)printf("%s", a);
	else printf("%s", a+1);
}

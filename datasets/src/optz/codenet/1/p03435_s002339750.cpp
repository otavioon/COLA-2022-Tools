#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[4],b[4],c[4][4];
	for(int i=1;i<4;i++)
		for(int j=1;j<4;j++)
			cin >> c[i][j];
	a[1]=0;
	for(int i=1;i<4;i++)
		b[i]=c[1][i]-a[1];
	for(int i=1;i<4;i++)
		a[i]=c[i][1]-b[1];
	for(int i=1;i<4;i++)
		for(int j=1;j<4;j++)
			if(a[i]+b[j] != c[i][j])
			{
				puts("No");
				return 0;			
			}	
	puts("Yes");
	return 0;
} 
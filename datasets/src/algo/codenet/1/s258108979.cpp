#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int c[4][4];
int main(){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			scanf("%d",&c[i][j]);
			int q,w,e;
			q=c[1][1]+c[2][2]+c[3][3];
			w=c[1][2]+c[2][3]+c[3][1];
			e=c[3][2]+c[2][1]+c[1][3];
	if(q==w&&e==w)
	printf("Yes");
	else printf("No");
}

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char c[5][5],d[5][5];
int main() {
	for (int i=1;i<=2;++i) scanf("%s",c[i]+1);
	for (int i=1;i<3;++i)
		for (int j=1;j<4;++j)
			d[3-i][4-j]=c[i][j];
	for (int i=1;i<3;++i)
		for (int j=1;j<4;++j)
			if (d[i][j]^c[i][j]) {
				puts("NO");
				return 0;
			}
	puts("YES");
	return 0;
}
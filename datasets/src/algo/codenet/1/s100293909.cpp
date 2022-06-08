#include<bits/stdc++.h>
using namespace std;
int a[4][4],n;
int main() {
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++) scanf("%d",&a[i][j]);
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++) {
			if(a[i][j]==(a[1][i]+a[2][j])) {
				printf("Yes\n");
				return 0;
			}
		}
	printf("No\n");
	return 0;
}
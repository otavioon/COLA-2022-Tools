#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[4][4]={};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	if((a[0][2]+a[1][1]+a[2][0]==a[0][1]+a[1][0]+a[2][2]) && (a[0][2]+a[1][1]+a[2][0]==a[0][0]+a[1][2]+a[2][1]))printf("Yes\n");
	else printf("No\n");
}
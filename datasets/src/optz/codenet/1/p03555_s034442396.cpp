#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	char a[3][4];
	char b[3][4];
	char t;
	for(int i=1;i<=2;i++){
		scanf(" %c %c %c",&a[i][1],&a[i][2],&a[i][3]);
	}
	b[1][1]=a[2][3];
	b[1][2]=a[2][2];
	b[1][3]=a[2][1];
	b[2][1]=a[1][3];
	b[2][2]=a[1][2];
	b[2][3]=a[1][1];
	if(b[1][1]==a[1][1]&&b[1][2]==a[1][2]&&b[1][3]==a[1][3]&&b[2][1]==a[2][1]&&b[2][2]==a[2][2]&&b[2][3]==a[2][3]){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}
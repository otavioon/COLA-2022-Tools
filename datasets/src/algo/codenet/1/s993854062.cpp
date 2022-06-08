#include<cstdio>
#include<algorithm>
#define maxn 120
using namespace std;
int c[4][4],N;
int read(){
	int w=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') w=w*10+c-48,c=getchar();
	return w;
}
int main(){
	int i,j;
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			c[i][j]=read();
		}
	}
	if((c[1][1]+c[2][2]+c[3][3])==(c[1][2]+c[2][1]+c[2][3]+c[3][2]-c[2][2])&&(c[1][1]+c[2][2]+c[3][3])==(c[1][3]+c[2][2]+c[3][1])) printf("Yes");
	else printf("No");
	return 0;
}
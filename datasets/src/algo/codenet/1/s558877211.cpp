#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(x,a,b) for(int x=a;x<=b;x++)
#define drep(x,a,b) for(int x=a;x>=b;x--)
#define rush() int T;scanf("%d",&T);while(T--)
#define wash(x,y) memset(x,y,sizeof(x));

int main(){
	int a[4][4];
	rep(i,1,3){
		rep(j,1,3)
			scanf("%d",&a[i][j]);
	}
	
	bool flag=(a[1][2]-a[1][1]==a[2][2]-a[2][1])&&
			(a[3][2]-a[3][1]==a[2][2]-a[2][1])&&
			(a[1][3]-a[1][2]==a[2][3]-a[2][2])&&
			(a[3][3]-a[3][2]==a[2][3]-a[2][2]);
	
	printf(flag?"Yes":"No");
}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;

const int MAXN = 5;
int a[MAXN][MAXN];

int main(){
	for(int i=0;i<3;i++){
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
	}
	int ans=0;
	int tri=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			ans+=a[i][j];
			if(i==j)	tri+=a[i][j];
		}
	}
	if(ans==3*tri){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}
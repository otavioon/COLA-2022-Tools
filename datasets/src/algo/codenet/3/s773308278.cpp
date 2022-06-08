#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <map>
#include <set>
using namespace std;
const long INF = 1000000009;

long n;
long a[100000];
long b[100000];
long c[100000];

long dp[2][100000];

int main(){
	scanf("%ld", &n);
	for(int i = 0; i < n; i++){
		scanf("%ld", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%ld", &b[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%ld", &c[i]);
	}
	sort(a, a+n);
	sort(b, b+n);
	sort(c, c+n);
	int vis = 0;
	for(int i = 0; i < n; i++){
		while(b[i] > a[vis] && vis < n){
			vis++;
		}
		dp[0][i] = vis;
	}
	vis = 0;
	/*for(int i = 0; i < n; i++){
		printf("%ld ", dp[0][i]);
	}
	printf("\n");*/
	for(int i = 0; i < n; i++){
		if(i != 0){
			dp[1][i] = dp[1][i-1];
		}
		while(c[i] > b[vis] && vis < n){
			//printf("%d\n", vis);
			dp[1][i] += dp[0][vis];
			vis++;
		}
	}
	long ans = 0;
	for(int i = 0; i < n; i++){
		ans += dp[1][i];
	}
	printf("%ld\n", ans);
	return 0;
}
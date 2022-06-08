#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
int ans = 1;
int hai[500] = {0};
int main(){
	int i, j, k;
	cin >> n >> m;
	for(i = 1; i <= 2 * m + 1; ++i){hai[i] = 1;}
	for(i = 2 * m + 1; i <= n; ++i){
		if(hai[i] == 0){
			ans += 1;
			for(j = i; j <= i + 1 + 2 * m; ++j){
				hai[j] = 1;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
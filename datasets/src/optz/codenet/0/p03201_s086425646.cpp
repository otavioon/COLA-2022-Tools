#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<cstdlib>
using namespace std;
typedef long long ll;

char s[200005];
int pos[200005];

int main(){
	scanf("%s", s);
	int len = strlen(s);
	int sum = 0;
	int cnt = 0;
	ll ans = 0;
	memset(pos, -1, sizeof(pos));
	for(int i = 0; i <= len - 1; i++){
		if(s[i] == 'B') cnt++;
		if(s[i] == 'W') {
			sum++;
			pos[sum] = cnt;
			ans = pos[sum] + ans;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
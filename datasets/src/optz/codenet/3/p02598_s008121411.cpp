#include <bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
	x = 0; int f(1); char c = getchar();
	for(;!isdigit(c);c = getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c = getchar()) x = (x<<3)+(x<<1)+c-'0';
	x *= f;
}
const int maxn = 200005;
int n,k,a[maxn];
bool judge(int);
int main(){
	read(n); read(k);
	int L = 1,R = 0,ans;
	for(int i(1);i <= n;++i)
		read(a[i]),R = max(R,a[i]);
	ans = R;
	while(L <= R){
		int mid = (L+R)>>1;
		if(judge(mid))	ans = mid,R = mid-1;
		else L = mid+1;
	} printf("%d\n",ans);
	return 0;
}
bool judge(int tans){
	int ret = 0;
	for(int i(1);i <= n;++i){
		if(a[i]%tans == 0)	ret += (a[i]/tans-1);
		else	ret += a[i]/tans;
	}
	return (ret <= k);
}
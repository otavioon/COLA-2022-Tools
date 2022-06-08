#include <iostream>
#include <algorithm>
using namespace std;
long long a[200005];
int flag[200005];
void dfs(long long now,long long cnt);
struct point{
	long long v;
	long long m;
	long long r , l;
	point(long long m = 0,long long v = 0,long long r = 0 ,long long l = 0):m(m),v(v),r(r),l(l){}
};
point node[200005];
int main()
{
	long long n,m;
	cin >> n >> m;
	for(long long i = 0; i < n - 1; i++){
		long long t, k;
		cin >> t >> k;
		flag[k] = 1;
		if(node[t].l){
			node[t].r = k;
		}else{
			node[t].l = k;
		}
	}
	int h;
	for(int i = 1; i <= n; i++){
		if(!flag[i]) h = i;
	}
	for(long long i = 0; i < m; i++){
		long long t,k;
		cin >> t >> k;
		node[t].v += k;
	}
	dfs(h,0);
	for(long long i = 0; i < n; i++){
		printf("%lld ",a[i + 1]);
	}
	return 0;
}
void dfs(long long now,long long cnt)
{
	if(node[now].r == 0 && node[now].l == 0){
		a[now] += cnt + node[now].v;
		return;
	}else{
		a[now] += cnt + node[now].v;
	}
	if(node[now].r){
		dfs(node[now].r,a[now]);
	}
	if(node[now].l){
		dfs(node[now].l,a[now]);
	}
	return;
}
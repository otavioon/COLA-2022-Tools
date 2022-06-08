#include<bits/stdc++.h>
#define For(i,l,r) for(int i = (l),i##end = (r);i <= i##end;i++)
#define Fordown(i,r,l) for(int i = (r),i##end = (l);i >= i##end;i--)
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;

template <typename T> inline bool chkmin(T &x,T y) { return y < x ? x = y,1 : 0; }
template <typename T> inline bool chkmax(T &x,T y) { return x < y ? x = y,1 : 0; }

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

int a[N],to[N << 1],nex[N << 1],beg[N],tot[N],Hash[N],vis[N];
int e,ans = 0;

inline int read() {
	int x = 0,flag = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-')ch = getchar();
	if(ch == '-')flag = -1,ch = getchar();
	while(isdigit(ch))x = (x << 3) + (x << 1) + (ch - '0'),ch = getchar();
	return x * flag;
}

inline void add(int x,int y) {
	to[++e] = y,nex[e] = beg[x],beg[x] = e;
}

inline void dfs(int x,int fa) {
	vis[x] = true;
	for(int i = beg[x];i;i = nex[i]) {
		if(to[i] == fa) continue;
		dfs(to[i],x);
		int val = min(tot[x],tot[to[i]]);
		ans += val;
		tot[x] -= val,tot[to[i]] -= val;
	}
}

int main() {

	int n = read();
	For(i,1,n) Hash[i] = a[i] = read();
	sort(Hash + 1,Hash + n + 1);
	int cnt = unique(Hash + 1,Hash + n + 1) - Hash - 1;
	For(i,1,n) tot[a[i] = lower_bound(Hash + 1,Hash + cnt + 1,a[i]) - Hash]++;

	For(i,1,cnt) For(j,1,30) {
		int val = (1 << j) - Hash[i];
		int pos = lower_bound(Hash + 1,Hash + cnt + 1,val) - Hash;
		if(Hash[pos] == val && (i ^ pos)) add(i,pos);
	}

	For(i,1,cnt) if(!vis[i]) dfs(i,0);
	For(i,1,cnt) {
		bool flag = false;
		For(j,0,30) if(Hash[i] == (1 << j)) flag = true;
		if(flag) ans += tot[i] / 2;
	}
	printf("%d\n",ans);

	return 0;
}
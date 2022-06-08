#include<cstdio>
#include<map>
#include<iostream>
#include<set>
#include<unordered_map>
using namespace std;
const int maxn = 200005;
unordered_map<int,set<int>>ma;
int er[35];
int lk[maxn],vis[maxn];
int en[maxn*50],la[maxn],nt[maxn*50],owo;
void adg(int x,int y) {
	en[++owo]=y; nt[owo]=la[x]; la[x]=owo;
}
bool hungary(int x,int id) {
	for(int it=la[x];it;it=nt[it]) {
		int y = en[it];
		if(vis[y]==id) continue;
		vis[y] = id;
		if((!lk[y])||(hungary(lk[y],id))) {
			lk[y] = x;
			return 1;
		}
	}
	return 0;
}
int main() {
	er[0]=1; for(int i=1;i<=30;i++) er[i] = er[i-1]*2;
	int ans = 0,n; scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		int x; scanf("%d",&x);
		for(int j=1;j<=30;j++) {
			if(er[j]>x&&(ma.count(er[j]-x))) {
				for(auto p:ma[er[j]-x]) {
					adg(p,i);
				}
			}
		}
		ma[x].insert(i);
	}
	for(int i=1;i<=n;i++) {
		ans += hungary(i,i);
	}
	printf("%d",ans);
}
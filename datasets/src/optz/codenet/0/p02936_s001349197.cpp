#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n,q;
int a,b,x,p;
int fa[N],id[N];	//build a tree
int ans[N];			//the value of each vertex
int tmp;
int find(int x) {
	if(id[x]==x)	return x;
	return id[x]=find(id[x]);
}
int main() {
	scanf("%d%d",&n,&q);
	fa[1]=1;
	for(int i=1;i<n;i++)
		scanf("%d%d",&a,&b),fa[b]=a,id[i]=i;
	for(int i=1;i<=q;i++) {
		scanf("%d%d",&x,&p);
		for(int j=1;j<=n;j++) {
			tmp=j;
			while(tmp!=x&&tmp>1) {	//find whether Vertex j is in the subtree rooted at Vertex x
				id[tmp]=fa[tmp];
				tmp=find(tmp);
			}
			if(tmp==x) {
				ans[j]+=p;
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
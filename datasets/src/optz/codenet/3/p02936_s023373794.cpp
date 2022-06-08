#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,q,sum[200005],visit[200005],ans[200005];
vector <int> dis[200005];
queue <int> que;

void bfs(int from,int sum){
	que.push(from);
	ans[from]+=sum;
	visit[from]=1;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		int len=dis[u].size();
		for(int i=0;i<len;i++){
			int t=dis[u][i];
			if(visit[t]==from)continue;
			que.push(t);
			ans[t]+=sum;
			visit[t]=from;
		}
	}
}

int main(void){
	scanf("%d %d",&n,&q);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		dis[a].push_back(b);
	}
	for(int i=1;i<=q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		sum[a]+=b;
	}
	for(int i=1;i<=n;i++){
		if(!sum[i])continue;
		bfs(i,sum[i]);
	}
	for(int i=1;i<=n;i++)
	printf("%d ",ans[i]);
}
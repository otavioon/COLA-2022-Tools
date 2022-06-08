#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<int>v[100001];
bool visit[100001];
queue<int >q;
int ctr=0,flag=0;
void bfs(int x){
    q.push(x);
    while(!q.empty()){ ctr++;
        x=q.front(); q.pop(); visit[x]=1;
        for(int y=0;y<v[x].size();y++){
            if(v[x][y]==2){
                flag=1; return;
            }
            if(!visit[v[x][y]]) q.push(v[x][y]);
        }
    }
}
int main() { memset(visit,0,sizeof(visit));
    int n,i;
    cin>>n;
    for(int x=1;x<=n;x++){
        cin>>i;
        v[x].push_back(i);
    }
    bfs(1);
    if(!flag) cout<<-1<<endl;
    else cout<<ctr<<endl;
	return 0;
}

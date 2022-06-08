#include<bits/stdc++.h>
using namespace std;

int parent[200010];
vector<int> child[200010];
long long int value[200010];
int height[200010];
vector<pair<int,int> > AB;

int dfs(int i,long long int parentsValue){
  long long int r=parentsValue;
  parentsValue+=value[i];
  value[i]+=r;
  for(vector<int>::iterator e=child[i].begin();e!=child[i].end();e++){
    dfs(*e,parentsValue);
  }
  return 0;
}

int main(){
  int N,Q;
  cin >> N >> Q;
  int a[N-1],b[N-1],p[Q],x[Q];
  for (int i=0;i<N+1;i++) parent[i]=0;
  for (int i=0;i<N+1;i++) value[i]=0;
  for (int i=0;i<N+1;i++) height[i]=200010;
  height[1]=0;
  for (int i=0;i<N-1;i++){
    cin >> a[i] >> b[i];
    pair<int,int> ab;
    ab.first=a[i];
    ab.second=b[i];
    AB.push_back(ab);
  }
  sort(AB.begin(),AB.end());

  for (vector<pair<int,int> >::iterator e=AB.begin();e!=AB.end();e++){
    if (height[e->first]>height[e->second]){
      int r=e->first;
      e->first=e->second;
      e->first=r;
    }
    child[e->first].push_back(e->second);
    height[e->second]=height[e->first]+1;
  }
  for (int i=0;i<Q;i++){
    cin >> p[i] >> x[i];
    value[p[i]]+=x[i];
  }

  dfs(1,0);

  for(int i=1;i<=N;i++){
    cout << value[i] <<" ";
  }
}

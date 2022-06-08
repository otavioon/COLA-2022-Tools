#include<bits/stdc++.h>
using namespace std;

vector <long long> edges[200010];
long long num[200010];

void dfs(int i,int p){
  for(int j:edges[i]) if (j!=p){
    num[j]+=num[i];
    dfs(j,i);
  }
}

int main(){
long long N;
  long long Q;
  cin>>N>>Q;
  for(int i=0; i<N; i++){
int a,b;
    cin>>a>>b;
    edges[a-1].push_back(b-1);
    edges[b-1].push_back(a-1);
  }
  for(int i=0; i<N; i++){
int p,x;
    cin>>p>>x;
    num[p-1]+=x;
  }
  
  dfs(0,-1);
  for(int i=0; i<N; i++){
    cout<<num[i]<<" \n";
      cout<<endl;
  }
}
  
  
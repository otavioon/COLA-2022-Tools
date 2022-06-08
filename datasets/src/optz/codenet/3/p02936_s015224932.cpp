#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
//#define rep1(i,n) for(ll i=1;i<=n;++i);
struct Tree{
  vector<int> top;
  int num;
  int count;
  void calc(){
    num=top.size();
    count=0;
  }
};
void solve(vector<Tree>& tree,int n,vector<int>& memo){
  queue<int> next;
  next.push(1);
  memo[1]==1;
  while(!next.empty()){
    int buf=next.front();
    next.pop();
    for(int i=0;i<tree[buf].num;i++){
      int buf2=tree[buf].top[i];
      if(memo[buf2]!=0)continue;
      next.push(buf2);
      tree[buf2].count+=tree[buf].count;
      memo[buf]=1;
    }
  }
  for(int i=1;i<=n;i++){
    cout<<tree[i].count<<" ";
  }
  cout<<endl;
}
int main(){
  int n,q;
  cin>>n>>q;
  vector<Tree> tree(n+1);
  vector<int> memo(n+1,0);
  int a,b;
  for(int i=0;i<n-1;i++){
    cin>>a>>b;
    tree[a].top.push_back(b);
    //    tree[b].top.push_back(a);
  }
  for(int i=1;i<=n;i++)tree[i].calc();
  int p,x;
  for(int i=0;i<q;i++){
    cin>>p>>x;
    tree[p].count+=x;
  }
  solve(tree,n,memo);
  return 0;
}

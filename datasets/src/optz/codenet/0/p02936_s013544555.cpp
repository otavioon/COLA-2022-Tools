
#include<bits/stdc++.h>
#include<math.h>
#include <stdio.h>
#include<vector>
#include<deque>
#include<stdlib.h>
//#include <algorithm>
#include<set>
#include <limits>
#include<iomanip>
#include<string>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define ll long long
#define d_5 100000
#define d9_7 1000000007
//非閉路グラフ、長さなし
int n;
struct graph{
  int num;
  vector<int> next;
  //bool past;//過去に通ったかを記録する
  int count;
  int depth;//頂点1からの距離
  int childnum;
  int result;
};
vector<graph> graphs;
void initgraph(int num){
  rep(i,num){
    graphs.push_back({i,{},0,0,0,0});
  }
  return;
}
void connectundire(int a,int b){
    graphs[a].next.push_back(b);
    graphs[b].next.push_back(a);
    return;
}
int search1(int num,int depth,int pre){//depthは何回再帰したか、という「最初の点からの深さ」
  graphs[num].depth=depth;
  int child=1;
  for(auto i:graphs[num].next){
    if(i==pre){
      continue;
    }
    child += search1(i,depth+1,num);
  }
  graphs[num].childnum=child;
  return child;
}
void search2(int num,int pre,int x){//depthは何回再帰したか、という「最初の点からの深さ」
  x+=graphs[num].count;
  graphs[num].result=x;
  for(auto i:graphs[num].next){
    if(i==pre){
      continue;
    }
    search2(i,num,x);
  }
  return;
}
void initcount(){
  rep(i,n){
    graphs[i].count=0;
  }
  return;
}
int main(void){
  int q;
  cin >> n >> q;
  int a,b;
  initgraph(n);
  graph root;
  rep(i,n-1){
    cin>> a >> b;
    a--;b--;
      connectundire(a,b);
  }
  search1(0,0,-1);
  int p,x;
  ll sum=0;
    initcount();
  rep(i,q){
    cin>>p>>x;
    p--;
    graphs[p].count+=x;
  }
  search2(0,-1,0);
  rep(i,n){
    cout<<graphs[i].result<<" ";
  }
	return 0;
}
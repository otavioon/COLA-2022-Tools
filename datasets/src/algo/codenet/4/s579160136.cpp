#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MA(i,j) make_pair(i,j)
#define PA pair<int,int>
#define PB push_back
#define PQ priority_queue<int>
#define PGQ priority_queue<int,vector<int>,greater<int> >
#define VE vector<int>
#define VP vector<PA>
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define MOD 1000000007
#define INF 1000000007
#define PI 3.14159265358979323846
using namespace std;
//
int main(){
  int N,K;
  set<int> S;
  cin>>N>>K;
  FOR(i,0,K){
    int D;
    cin>>D;
    S.insert(D);
  }
  while(S.find(N%10)!=S.end()){
    if(N%10==9){
      N+=10;
      break;
    }else{
      N+=1;
    }
  }
  while(S.find(N%100/10)!=S.end()){
    if(N%100/10==9){
      N+=100;
      break;
    }else{
      N+=10;
    }
  }
  while(S.find(N%1000/100)!=S.end()){
    if(N%1000/100==9){
      N+=1000;
      break;
    }else{
      N+=100;
    }
  }
  while(S.find(N%10000/1000)!=S.end()){
    if(N%10000/1000==9){
      N+=10000;
      break;
    }else{
      N+=1000;
    }
  }
  cout<<N<<endl;
  return 0;
}

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
  string N;
  int K;
  set<char> S;
  FOR(i,0,10){
    S.insert('0'+i);
  }
  cin>>N>>K;
  FOR(i,0,K){
    char D;
    cin>>D;
    S.erase(D);
  }
  FOR(i,0,(int)N.size()){
    if(S.find(N[i])!=S.end()){
      cout<<N[i];
    }else{
      cout<<*upper_bound(S.begin(),S.end(),N[i]);
    }
  }
  cout<<endl;
  return 0;
}

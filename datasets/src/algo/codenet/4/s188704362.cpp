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
  set<char> S;
  cin>>N>>K;
  FOR(i,0,K){
    char D;
    cin>>D;
    S.insert(D);
  }
  while(1){
    int n=N;
    while(1){
      if(S.find('0'+n%10)!=S.end()){
        break;
      }
      n/=10;
      if(n==0){
        cout<<N<<endl;
        return 0;
      }
    }
    N++;
  }
}

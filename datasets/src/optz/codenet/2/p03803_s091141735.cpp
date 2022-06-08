#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define uLL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

using namespace std;

vector<int> graph[1000];

int main(void){
  int N, M, Q;                  // 頂点の数N，辺の数M，インプットの数Q
  cin>>N>>M;
  int cnt=0;

  FORQ(i,1,N){
    graph[i].push_back(0);
  }

  FOR(i,0,M){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }


  int loop3SucFlag=0;
  int loop2FailFlag=0;
  vector<int> v(N+1);
  FORQ(i,1,N){
    v[i]=i;
  }

  do{
    FORQ( i,1,v.size()-2 ) {
      FORQ ( j,0,graph[v[i]].size() ) {
        if(graph[v[i]][j]==v[i+1]){
          loop3SucFlag=1;
          break;
        }else{
        }
      }

      if(loop3SucFlag==0){
        loop2FailFlag=1;
        break;
      }
      loop3SucFlag=0;
    }

    if(loop2FailFlag==0){
      cnt++;
    }
    loop2FailFlag=0;
    
  }while(   next_permutation(  v.begin()+1,v.end()  )   &&  v[1]==1);

  cout<<cnt<<endl;
  return 0;
}

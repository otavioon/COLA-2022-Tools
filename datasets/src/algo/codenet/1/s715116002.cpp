#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  int c[3][3];
  REP(i,3)REP(j,3)cin>>c[i][j];
  if(c[0][0]+c[1][1]+c[2][2]==c[0][1]+c[1][2]+c[2][0] and
  c[0][1]+c[1][2]+c[2][0]==c[0][2]+c[1][0]+c[2][1]){
    cout<<"Yes"<<endl;
  }
  else cout<<"No"<<endl;
  return 0;
}

#include<stdio.h>
#include<vector>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

using namespace std;

int main(){
  int c[3*3],x,y,z,w;
  REP(i,9) scanf("%d",&c[i]);
  x = c[0] + c[4] - c[3] - c[1];
  y = c[1] + c[5] - c[2] - c[4];
  z = c[3] + c[7] - c[4] - c[6];
  w = c[4] + c[8] - c[5] - c[7];
  if(x==0&y==0&z==0&w==0) printf("Yes\n");
  else printf("No\n");
  return 0;
}

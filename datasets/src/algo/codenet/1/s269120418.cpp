#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int c[3][3];
int a[3];
int b[3];
const int INF = 1001001001;
int main(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>c[i][j];
    }
  }
  int d1,d2;
  d1=c[0][1]-c[0][0];
  d2=c[0][2]-c[0][1];
  
  if(c[1][1]-c[1][0]==d1&&c[1][2]-c[1][1]==d2){
      if(c[2][1]-c[2][0]==d1&&c[2][2]-c[2][1]==d2){
          cout<<"Yes"<<endl;return 0;
      }
  }
  cout<<"No"<<endl;
  return 0;
}
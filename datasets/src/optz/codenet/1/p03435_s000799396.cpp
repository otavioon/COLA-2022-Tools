#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;


int main() {
  int c[5][5];
  for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
        cin>>c[i][j];
     }
  }
  
  int dis1=c[0][1]-c[0][0];
  int dis2=c[0][2]-c[0][1];

  for(int i=1;i<3;i++){
      if((c[i][1]-c[i][0])!=dis1||(c[i][2]-c[i][1])!=dis2){
       cout<<"No"<<endl;return 0;
      }
     }
   cout<<"Yes"<<endl;
   return 0;
  }
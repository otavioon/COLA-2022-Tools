#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int A[3][3];
  rep(i,3){
    rep(j,3) cin>>A[i][j];
  }
  
  if(A[0][1]-A[0][0]==A[1][1]-A[1][0] && A[0][1]-A[0][0]==A[2][1]-A[2][0] && A[0][2]-A[0][0]==A[1][2]-A[1][0] && A[0][2]-A[0][0]==A[2][2]-A[2][0]) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
  return 0;
}
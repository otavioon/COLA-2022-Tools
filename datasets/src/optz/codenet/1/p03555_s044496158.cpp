#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  vector<vector<char>> C(2,vector<char>(3));
  rep(i,2) rep(j,3) cin>>C[i][j];
  if(C[0][0]==C[1][2] && C[0][1]==C[1][1] && C[0][2]==C[1][0])
    cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}

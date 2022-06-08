#include "bits/stdc++.h" 
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
typedef long long ll;

int c[3][3];

void solve(){
  int x, y, z;
  x = c[0][0] + c[1][1] + c[2][2];
  y = c[0][1] + c[1][2] + c[2][0];
  z = c[0][2] + c[1][0] + c[2][1];
  if (x == y && y == z){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}

int main(){
  rep(i, 3){
    rep(j, 3){
      cin >> c[i][j];
    }
  }
  solve();
}
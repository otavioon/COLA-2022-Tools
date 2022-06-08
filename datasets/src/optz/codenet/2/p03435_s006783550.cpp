#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
#include<string>
#include<cstdlib>
#include<cctype>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF = 1LL << 40;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
// ----------------------------------------------------------------------------

int main(){
  vector<vector<int>> c(4,vector<int> (4));
  for(int i=1; i<=3; i++){
    for(int j=1; j<=3; j++){
      cin >> c[i][j];
    }
  }
  bool can = false;
  for(int i=0; i<=c[1][1]; i++){
    for(int j=0; j<=c[1][2]; j++){
      for(int k=0; k<=c[1][3]; k++){
        bool temp=true;
        for(int l=1;l<=3;l++){
          if(c[l][1]-i==c[l][2]-j && c[l][2]-j==c[l][3]-k){
          }else{
            temp = false;
          }
        }
        if(temp){
          can = true;
        }
      }
    }
  }
  if(can){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}

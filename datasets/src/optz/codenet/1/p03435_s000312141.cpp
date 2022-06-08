#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int main(){
  int a[3][3];
  int x[3];
  int y[3];
  
  rep(i,3){
    rep(j,3){
      cin >> a[i][j];
    }
  }
  
  x[0] = 0;
  rep(i,3) y[i] = a[0][i] - x[0];
  rep(i,3) x[i] = a[i][0] - y[0];
  
  rep(i,3){
    rep(j,3){
      if(a[i][j] != x[i] + y[j]){
        cout << "No";
        return 0;
      }
    }
  }
  
  cout << "Yes";
  
  return 0;
}
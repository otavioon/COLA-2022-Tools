#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int c[3][3];
  rep(i, 3)
    rep(j, 3)
    cin >> c[i][j];
  //入力終了

  //下のように足し算をすると，
  //(a1+a2+a3) + (b1+b2+b3) = C
  //の方程式が3つ現れる
  //Cの値がいずれも等しければ題意を満たす組み合わせがある
  
  int p = c[0][0] + c[1][1] + c[2][2];
  int q = c[0][1] + c[1][2] + c[2][0];
  int r	= c[0][2] + c[1][0] + c[2][1];

  if(p == q && q == r)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}

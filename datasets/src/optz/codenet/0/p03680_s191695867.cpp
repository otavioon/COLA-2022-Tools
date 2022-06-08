//  cout << char(i+48) << endl;//なぜかaは47と得る時がある。+48で出力もaにできる。
//  cout << char(97) << endl;//アスキーコードでaを出力
// sort(b.begin(), b.end());//bという配列を小さい方からソート
// reverse(b.begin(), b.end());//bという配列をリターン
// 10桁でdouble出力するパターン１ 
// printf("%.10f\n", ma);
// 10桁でdouble出力するパターン２
//cout << fixed << setprecision(10);
//  cout << ma << endl;

/*01 02 03 12 13 23　と６回見ていくパターン 
for(int i=0;i<n-1;i++){
  for(int j=i+1;j<n;j++){
    }
  }
*///vector<vector<int>> data(3, vector<int>(4));//int型の2次元配列(3×4要素の)の宣言
//int64_t a;
//10のi乗pow(10, i);
/*string s; stringでの文字列を数字型に変える方法
  cin >> s;
  rep(i,s.size()-2) {
  int a= (s.at(i)-'0')*100 + (s.at(i+1)-'0')*10+ s.at(i+2) -'0';
    */
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  rep(i,n) cin >> a.at(i);
  rep(i,n) a.at(i)--;
  int x=-1;
  int y=-2;
  int z=-3;
  int v=-4;
//  rep(i,n) cout << a.at(i) << endl;
  int count = 0;
  int num = 0;
      num = a.at(0);
  count ++;
  for(;;){
    if(num == 1) break;
    else if(x == z || y ==v){
      count = -1;
      break;
    }
    num = a.at(num);
    count ++;
    if(count%4==0){
      x = num;
    }
    else if(count%4==1){
      y = num;
    }
    else if(count%4==2){
      z = num;
    }
    else{
      v = num;
    }
  }
  cout << count << endl;
}
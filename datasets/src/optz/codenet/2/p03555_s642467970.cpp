#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<vector<string>> vec(3, vector<string>(4));
  int i,j;
  for (int i = 1; i < 3; i++) {
    for (int j = 1; j < 4; j++) {
      cin >> vec.at(i).at(j);
    }
  }
 string ans = "NO";
 int count = 0;
 for (int n=1; n<4; n++){
    if (vec.at(1).at(n) == vec.at(2).at(abs(4-n))){
      count ++;
    }
 }
 if (count == 3){
   ans = "YES";
 }
  cout << ans << endl;
}
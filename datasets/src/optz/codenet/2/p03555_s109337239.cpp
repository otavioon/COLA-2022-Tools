#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<vector<string>> vec(2, vector<string>(3));
  int i,j;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> vec.at(i).at(j);
    }
  }
 string ans = "NO";
 int count = 0;
 for (int n=0; n<3; n++){
    if (vec.at(0).at(n) == vec.at(1).at(abs(2-n))){
      count ++;
    }
 }
 if (count == 3){
   ans = "YES";
 }
  cout << ans << endl;
}
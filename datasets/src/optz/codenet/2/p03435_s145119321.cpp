#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>> c(3,vector<int>(3));
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3;j++){
      cin >> c.at(i).at(j);
    }
  }
  //行ごとの最小値を求める
  int min_c1 = min(c.at(0).at(0),min(c.at(0).at(1),c.at(0).at(2)));
  int min_c2 = min(c.at(1).at(0),min(c.at(1).at(1),c.at(1).at(2)));
  int min_c3 = min(c.at(2).at(0),min(c.at(2).at(1),c.at(2).at(2)));
  bool ans = false;
  for(int i = 0; i <= min_c1;i++){
    for(int j = 0; j <= min_c2;j++){
      for(int k = 0;k <= min_c3;k++){
        int b1 = c.at(0).at(0) - i;
        int b2 = c.at(0).at(1) - i;
        int b3 = c.at(0).at(2) - i;
        if((i + b1) != c.at(0).at(0))continue;
        if((i + b2) != c.at(0).at(1))continue;
        if((i + b3) != c.at(0).at(2))continue;
        if((j + b1) != c.at(1).at(0))continue;
        if((j + b2) != c.at(1).at(1))continue;
        if((j + b3) != c.at(1).at(2))continue;
        if((k + b1) != c.at(2).at(0))continue;
        if((k + b2) != c.at(2).at(1))continue;
        if((k + b3) != c.at(2).at(2))continue;
        ans = true;
      }
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
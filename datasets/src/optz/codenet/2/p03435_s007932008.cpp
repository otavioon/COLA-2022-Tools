#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  vector<vector<int>> c(3,vector<int>(3, 0));

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cin >> c.at(i).at(j);
    }
  }

  bool flg = false;
  int range = 1000;
  for(int a1 = -range; a1 <= range; a1++){
    // cerr << a1 << endl;
    int b1 = c[0][0] - a1;
    int b2 = c[0][1] - a1;
    int b3 = c[0][2] - a1;

    int a2 = a1 - c[0][0] + c[1][0];
    int a3 = a1 - c[0][0] + c[2][0];

    bool f1 = (a2 + b2 == c[1][1]);
    bool f2 = (a2 + b3 == c[1][2]);
    bool f3 = (a3 + b2 == c[2][1]);
    bool f4 = (a3 + b3 == c[2][2]);
    flg = f1 && f2 && f3 && f4;
    if(flg) break;
  }

  cout << (flg ? "Yes" : "No") << endl;

}


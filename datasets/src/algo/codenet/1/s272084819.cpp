#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll c[3][3], sum1 ,sum2, sum3;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cin >> c[i][j];
    }
  }

  sum1 = c[0][0] + c[1][1] + c[2][2];
  sum2 = c[0][1] + c[1][2] + c[2][0];
  sum3 = c[0][2] + c[1][0] + c[2][1];

  if (sum1 == sum2 && sum2 == sum3) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1000000007;


int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);


    double c[2][2];
    for ( int i = 0; i < 3; i++ ){
      for (int  j =0; j < 3; j++){
        cin >> c[i][j];
      }
    }

    if( (c[1][1]/c[1][2] == c[2][1]/c[2][2] ==c[3][1]/c[2][3] )&& (c[1][1]/c[1][3] ==c[2][1]/c[2][3] ==c[3][1]/c[3][3])) {
      cout << "Yes" << endl;
    }

    else {cout << "No" << endl;}



    return 0;

}

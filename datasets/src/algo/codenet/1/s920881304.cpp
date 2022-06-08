#include<bits/stdc++.h>
using namespace std;

int c[3][3];

int main(){
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin >> c[i][j];

    if(c[1][2]-c[1][1] == c[0][2]-c[0][1] && c[2][2]-c[2][1] == c[0][2]-c[0][1]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

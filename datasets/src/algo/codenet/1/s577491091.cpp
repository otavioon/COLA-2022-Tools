#include <bits/stdc++.h>
using namespace std;

int main(){
    int c[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> c[i][j];
        }
    }
    int dif1 = c[0][1] - c[0][0];
    int dif2 = c[0][2] - c[0][1];

    if(c[1][1] - c[1][0] == dif1 && c[1][2] - c[1][1] == dif2 
    && c[2][1] - c[2][0] == dif1 && c[2][2] - c[2][1] == dif2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
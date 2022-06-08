#include <iostream>
using namespace std;

int main(){
    int c[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> c[i][j];
        }
    }
    int a = c[0][0] + c[1][1] + c[2][2];
    int b = c[1][0] + c[2][1] + c[0][2];
    int x = c[2][0] + c[0][1] + c[1][2];
    if(a==b && b==x) cout <<"Yes" <<"\n";
    else cout <<"No" <<"\n";

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string ans = "Yes";
    int c[3][3];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
        cin >> c[i][j];
        }
    }
    if(c[0][0]-c[1][0]!=c[0][1]-c[1][1]||c[0][1]-c[1][1]!=c[0][2]-c[1][2]){
        ans = "No";
    }
    if(c[1][0]-c[2][0]!=c[1][1]-c[2][1]||c[1][1]-c[2][1]!=c[1][2]-c[2][2]){
        ans = "No";
    }
    cout << ans << endl;
}
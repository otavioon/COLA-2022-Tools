#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <sstream>
#define ull unsigned long long
#define ll long long
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int c[3][3],c_1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> c_1;
            c[i][j]=c_1;
        }
    }
    if(c[0][0]+c[1][1]+c[2][2]==c[0][2]+c[1][1]+c[2][0] && c[0][1]+c[1][1]+c[2][1]!=c[1][0]+c[1][1]+c[1][2]){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}
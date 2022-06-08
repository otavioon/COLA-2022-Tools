#include <bits/stdc++.h>
using namespace std;

int main() {
    char c[2][3];
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> c[i][j];
        }
    }
    
    for(int i = 0; i < 3; ++i){
        if(c[0][i] != c[0][3-i-1]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
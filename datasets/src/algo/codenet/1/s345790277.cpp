#include <bits/stdc++.h>
using namespace std;

int main() {
    int c11,c12,c13,c21,c22,c23,c31,c32,c33;
    cin >> c11 >> c12 >> c13 >> c21 >> c22 >> c23 >> c31 >> c32 >> c33;

    int a1,a2,a3,b1,b2,b3;
    for (a1 = 0; a1 <= 100; ++a1) {
        b1 = c11 - a1;
        b2 = c12 - a1;
        b3 = c13 - a1;
        a2 = c21 - b1;
        a3 = c31 - b1;
        if(a2 + b2 == c22 && a2 + b3 == c23 && a3 + b2 == c32 && a3 + b3 == c33) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}

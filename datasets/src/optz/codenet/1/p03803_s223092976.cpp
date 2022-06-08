#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int list[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1};
    int anum, bnum;
    for (int i = 0; i < 13; i++) {
        if (a == list[i]) {
            anum = i;
        }
        if (b == list[i]) {
            bnum = i;
        }
    }
    if (anum < bnum) {
        cout << "Bob";
    } else if (anum > bnum) {
        cout << "Alice";
    } else {
        cout << "Draw";
    }

        return 0;
}
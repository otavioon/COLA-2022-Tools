#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum_cells;
    for (int i = 0; i < 3; i++) {
        int c1, c2, c3;
        cin >> c1 >> c2 >> c2;
        sum_cells += c1 + c2 + c3;
    }
    if (sum_cells % 3 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum = 0, tr = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            int c;
            cin >> c;
            tr += (i == j) * c;
            sum += c;
        }
    }
    cout << (sum == 3 * tr ? "Yes" : "No") << endl;
}

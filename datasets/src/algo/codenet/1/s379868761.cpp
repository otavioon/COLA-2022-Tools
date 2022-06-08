#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        int c;
        cin >> c;
        sum += c;
    }
    cout << (sum % 3 ? "No" : "Yes") << endl;
}

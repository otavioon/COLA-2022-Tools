#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    int Sum = 0, diagSum = 0;
    for (int i = 0; i < 9; ++i) {
        int x;
        cin >> x;
        Sum += x;
        if (i == 0 || i == 4 || i == 8)
            diagSum += x;
    }
    if (Sum % 3 == 0 && Sum / 3 == diagSum)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

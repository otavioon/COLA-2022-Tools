#include <iostream>
using namespace std;

int main() {
    int c[9];
    for (int i = 0; i < 9; ++i) cin >> c[i];

    int sum1 = c[0] + c[4] + c[8];
    int sum2 = c[1] + c[5] + c[6];
    int sum3 = c[2] + c[3] + c[7];
    int sum4 = c[0] + c[5] + c[7];
    int sum5 = c[1] + c[3] + c[8];
    int sum6 = c[2] + c[4] + c[6];

    if (sum1 == sum2 && sum2 == sum3 && sum4 == sum5 && sum5 == sum6) cout << "Yes" << endl;
    else cout << "No" << endl;
}
#include <iostream>
using namespace std;

int abs(int d, int e) {
    int calc;
    calc = d - e;
    if(calc < 0) {
        return calc *= -1;
    } else {
        return (calc);
    }
}

int main() {
    int n;
    int a[n];
    int ab, calc, max = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int k = 0; k < n - 1; k++) {
        for (int j = k + 1; n - j > 0; j++) {
            ab = abs(a[k] - a[j]);
            max = max < ab ? ab : max;
        }
    }
    cout << max << endl;
}
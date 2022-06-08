#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;

    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    int is_ok = false;
    int min = 5000;

    for (int i = 0; i < n; i++) {
        int suma = 0, sumb = 0, sumc = 0;
        for (int j = i; j < n; j++) {
            suma += a[j];
            sumb += b[j];
            sumc += c[j];

            if (suma * mb == sumb * ma) {
                if (min > sumc) {
                    min = sumc;
                    is_ok = true;
                }
            }
        }
        if (is_ok) { break; }
    }

    if (is_ok) {
        cout << min << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
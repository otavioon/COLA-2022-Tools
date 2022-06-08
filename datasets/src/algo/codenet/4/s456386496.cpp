#include<iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int a[10] = {0};
    for (int i = 0; i < k; ++i) {
        int aa;
        cin >> aa;
        a[aa]++;
    }
    while (1) {
        int tmp = n;
        int flg = 0;
        while (tmp) {
            for (int i = 0; i <= 9; ++i) {
                if (tmp % 10 == i && a[i]) {
                    flg++;
                    break;
                }
            }
            if (flg) {
                break;
            }
            if (tmp / 10 == 0) { //先にflg
                cout << n << endl;
                return 0;
            }
            tmp /= 10;
        }
        n++;
    }
}


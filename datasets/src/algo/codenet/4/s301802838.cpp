#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
    set<int> D;
    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        D.insert(d);
    }

    for (int i = N; i <= 10 * N; i++) {
        bool flag = true;
        int tmp = i;
        while (tmp > 0) {
            int digit = tmp % 10;
            if (D.find(digit) != D.end()) {
                flag = false;
                break;
            }
            tmp /= 10;
        }
        if (flag) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
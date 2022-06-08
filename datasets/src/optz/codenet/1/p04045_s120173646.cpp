#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N, K, tmp;
    bool ok[10];

    for (int i = 0; i < 10; i++) {
        ok[i] = true;
    }

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> tmp;
        ok[tmp] = false;
    }

    int extra = 0;
    vector<int> result;

    while (N > 0 || extra > 0) {
        int current = N % 10 + extra;
        extra = 0;
        N /= 10;

        for (int i = 0; i < 10; i++) {
            int x = (current + i) % 10;
            if (ok[x]) {
                result.push_back(x);
                if (x < current) {
                    extra = 1;
                }
                break;
            }
        }
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}

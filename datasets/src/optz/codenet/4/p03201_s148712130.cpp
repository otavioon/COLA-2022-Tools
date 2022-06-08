// AGC029 B
#include <iostream>
#include <set>

using namespace std;

bool is_power2(int n) {
    while (n > 1) {
        if (n % 2 != 0) return false;
        n /= 2;
    }

    return true;
}

int main() {
    int N;
    cin >> N;
    set<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.insert(a);
    }

    int ret = 0;
    while (!A.empty()) {
        auto it = A.end();
        it--;
        int val = *it;
        A.erase(it);

        for (it = A.begin(); it != A.end(); ++it) {
            if (is_power2(*it + val)) {
                A.erase(it);
                ++ret;
                break;
            }
        }
    }

    cout << ret << endl;
    return 0;
}
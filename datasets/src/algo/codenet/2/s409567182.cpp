// AGC029 B
#include <iostream>
#include <set>

using namespace std;
using ll = long long;
#define int ll

signed main() {
    int N;
    cin >> N;
    multiset<int> A;
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

        int tmp = 1;
        while (tmp < val) tmp *= 2;

        it = A.find(tmp - val);
        if (it != A.end()) {
            A.erase(it);
            ++ret;
        }
    }

    cout << ret << endl;
    return 0;
}
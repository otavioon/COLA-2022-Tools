#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, cnt, next;
    cin >> n;
    vector<bool> isPushed(n, false);
    vector<int>  data(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> data.at(i);
    }

    cnt  = 0;
    next = 1;

    while (true) {
        if (next == data.at(next - 1) || isPushed.at(next - 1)) {
            cout << -1 << endl;
            return 1;
        }
        cnt++;
        isPushed.at(next - 1) = true;
        if (data.at(next - 1) == 2) {
            break;
        } else {
            next = data.at(next - 1);
        }
    }

    cout << cnt << endl;
    return 0;
}

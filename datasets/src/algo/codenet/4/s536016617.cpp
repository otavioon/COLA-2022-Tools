#include <bits/stdc++.h>
using namespace std;

const int MAXV = 10000;

bool check_num(int i, set<int> D) {
    string str = to_string(i);
    for (auto ch : str) {
        if (D.find(ch - '0') != D.end()) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    set<int> D;
    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        D.insert(d);
    }
    for (int i = N; i < MAXV; i++) {
        if (check_num(i, D)) {
            cout << i << endl;
            break;
        }
    }


    return 0;
}

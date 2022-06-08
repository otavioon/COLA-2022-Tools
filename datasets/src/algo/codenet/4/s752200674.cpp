#include <bits/stdc++.h>

#ifdef _DEBUG
#define debug(x) cout<<#x<<": "<<x<<endl
#else
#define debug(x)
#endif

using namespace std;

int main() {
    int N; int K;
    cin >> N >> K;
    set<int> ds;
    for (int i = 0; i < K; ++i) {
        int d;
        cin >> d;
        ds.insert(d);
    }

    for (int n = N;; ++n) {
        string n_str = to_string(n);
        bool found = false;
        for (const auto d : n_str) {
            if (ds.count(d - '0')) {
                found = true;
            }
        }
        if (found) { continue; }
        cout << n << endl;
        break;
    }
}
#include <iostream>
#include <set>

using namespace std;
#define repp(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)

typedef long long ll;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main() {
    int N, K;
    cin >> N >> K;
    set<char> hateNumbers;
    repp(i, 0, K) {
        char d;
        cin >> d;
        hateNumbers.insert(d);
    }

    repp(i, N, 100000) {
        string res = to_string(i);
        bool ok = true;
        for (auto c : res) ok &= hateNumbers.find(c) == hateNumbers.end();

        if (ok) {
            cout << res << endl;
            return 0;
        }
    }
}


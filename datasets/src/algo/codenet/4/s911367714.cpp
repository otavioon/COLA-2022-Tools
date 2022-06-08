#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long i64;

set<int> D;
bool hate(i64);

int main(void) {
    i64 N, K;
    cin >> N >> K;

    int d, i;
    for (i=0; i<K; i++) {
        cin >> d;
        D.insert(d);
    }

    while (hate(N)) {
        N++;
    }

    cout << N << endl;

    return 0;
}


bool hate(i64 N) {
    int d;
    while (N) {
        d = N % 10;
        if (D.count(d)) return true;

        N /= 10;
    }
    return false;
}

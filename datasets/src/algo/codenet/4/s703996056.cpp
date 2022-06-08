#include <cstdio>
#include <set>

using namespace std;

bool is_valid(const set<int> &D, int N) {
    while (N) {
        if (D.count(N%10)) return false;

        N /= 10;
    }
    return true;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    set<int> D;
    for (int i=0; i<K; ++i) {
        int d;
        scanf("%d", &d);
        D.insert(d);
    }

    while (!is_valid(D, N))
        ++N;

    printf("%d\n", N);
    return 0;
}

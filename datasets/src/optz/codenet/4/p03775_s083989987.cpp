#include "bits/stdc++.h"

using namespace std;

long long F(long long A, long long B) {
    long long n = max(A, B);
    long long ret = 0;
    while (n > 0) {
        n /= 10LL;
        ++ret;
    }
    return ret;
}

void Main() {
    long long N;
    cin >> N;

    set<long long> factors;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            factors.insert(i);
            factors.insert(N / i);
        }
    }
    long long ans = 1000000000000000000LL;
    for (long long l : factors) {
        long long f = F(l, N / l);
        ans = min(ans, f);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

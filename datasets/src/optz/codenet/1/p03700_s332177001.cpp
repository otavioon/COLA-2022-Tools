// https://beta.atcoder.jp/contests/abc063
// status: [review]

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;
using ui64 = uint64_t;
using i64 = int64_t;

const int MAX_N = 100000;
int h[MAX_N];
int N, A, B;
int diff;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(4 5 3
8
7
4
2
)");
#endif
    stream >> N >> A >> B;
    for (int i = 0; i < N; ++i) stream >> h[i];
    diff = A - B;

    i64 left = 1, right = static_cast<i64>(1e9);
    while (1 < right - left) {
        auto mid = (right + left) / 2;

        // Aで攻撃する必要がある回数の総和
        i64 sum_a_attack = 0;
        for (auto u : h) {
            auto extra_cost = u - mid * B;
            if (0 < extra_cost) sum_a_attack += (diff + extra_cost - 1) / diff;
        }

        if (mid < sum_a_attack) left = mid;
        else right = mid;
    }
    cout << right << endl;
    return 0;
}
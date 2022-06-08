#include <algorithm>
#include <cstdio>
const int MAXL = 1001;
int cnt[MAXL];
int pre[MAXL];
int L, N;

void init() {
    for (int i = 0; i < MAXL; ++i) {
        cnt[i] = 0;
    }
}

int solve() {
    pre[0] = cnt[0];
    for (int i = 1; i < MAXL; ++i) {
        pre[i] = pre[i-1] + cnt[i];
    }
    int sum = 0;
    for (int i = 1; i < MAXL; ++i) {
        if (!cnt[i]) continue;
        --cnt[i];
        for (int j = i; j < MAXL; ++j) {
            if (!cnt[j]) continue;
            --cnt[j];
            int k = std::min(i+j, MAXL) - 1;
            sum += pre[k] - pre[j] + cnt[j];
            ++cnt[j];
        }
        ++cnt[i];
    }
    return sum;
}

int main() {
    scanf("%d", &N);
    init();
    for (int i = 0; i < N; ++i) {
        scanf("%d", &L);
        ++cnt[L];
    }
    printf("%d\n", solve());
    return 0;
}
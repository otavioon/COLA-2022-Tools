#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int a[maxn], b[maxn], c[maxn];
int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    LL ans = 0;
    for (int i = 1; i <= N; i++) scanf("%d", a+i);
    for (int i = 1; i <= N; i++) scanf("%d", b+i);
    for (int i = 1; i <= N; i++) scanf("%d", c+i);
    sort(a+1, a+N+1); sort(b+1, b+N+1); sort(c+1, c+N+1);
// printf("%d\n", c[1]);
    for (int i = 1; i <= N; i++) {
        int ub = N, lb = 0;
        LL t1 = 1, t2 = 0;
        while (ub >= lb) {
            int mid = (ub+lb)/2;
            if (a[mid] < b[i]) {
                t1 = mid;
                lb = mid + 1;
            }
            else ub = mid - 1;
        }
        ub = N, lb = 1;
        while (ub >= lb) {
            int mid = (ub+lb)/2;
            // printf("%d\n", mid);
            if (c[mid] > b[i]) {
                t2 = mid;
                // printf("%d %d\n", c[mid], b[i]);
                ub = mid - 1;
            }
            else lb = mid + 1;
        }
        // printf("%d %d\n", t1, t2);
        ans += t1*(N-t2+1);
    }
    printf("%lld\n", ans);
    return 0;
}
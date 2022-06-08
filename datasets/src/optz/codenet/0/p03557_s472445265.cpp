    #include <cstdio>
    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <vector>

    const int MAX_N = 100000;
    int n;
    int a[MAX_N], b[MAX_N], c[MAX_N];

    int main(void) {
        std::scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            std::scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            std::scanf("%d", &b[i]);
        }
        for (int i = 0; i < n; i++) {
            std::scanf("%d", &c[i]);
        }
        std::sort(a, a + n);
        std::sort(b, b + n);
        std::sort(c, c + n);
        long long x = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; a[i] < b[j]; j--) {
                for (int k = n - 1; b[j] < c[k]; k--) {
                    x++;
                }
            }
        }
        std::printf("%lld\n", x);
        return 0;
    }
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string S;
    long long K;
    cin >> S >> K;
    long long length = S.length();
    long long count = 0, same = 1;
    if (S[0] != S[length - 1]) {
        for (int i = 1; i < length; i++) {
            if (S[i] == S[i - 1]) {
                ++same;
            } else {
                count += same / 2;
                same = 1;
            }
        }
        count *= K;
    } else {
        long long first, last;
        for (first = 0; first < length - 1; ++first) {
            if (S[first] != S[0]) {
                break;
            }
        }
        for (last = length - 1; last > first; --last) {
            if (S[last] != S[length - 1]) {
                break;
            }
        }
        if (first == length - 1) {
            count = length * K / 2;
        } else {
            for (int i = first; i <= last; i++) {
                if (S[i] != S[i - 1]) {
                    count += same / 2;
                    same = 1;
                } else {
                    ++same;
                }
            }
            count += same / 2;
            count *= K;
            count += ((first + (length - last - 1)) / 2) * (K - 1);
            count += (first) / 2;
            count += (length - last - 1) / 2;
        }
    }
    printf("%lld\n", count);
    return 0;
}

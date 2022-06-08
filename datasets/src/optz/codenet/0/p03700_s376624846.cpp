#include <bits/stdc++.h>

using namespace std;

int N, A, B, h[100010];

bool check(int S) {
    int cpy = S;
    for (int i = 0; i < N; i++) {
        int x = (h[i] - B * S + A - B - 1) / (A - B);
        if (x > S) return false;
        else cpy -= max(0, x);  
    }
    if (cpy < 0) return false;
    return true;
}

int main(void) {
    cin >> N >> A >> B;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
        sum += h[i];
    }
    
    long long l = -1, r = sum / N + 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m + 1;
    }
    cout << r << endl;

    return 0;
}
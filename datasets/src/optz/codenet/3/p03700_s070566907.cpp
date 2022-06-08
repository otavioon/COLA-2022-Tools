#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
using namespace std;

bool check(int t, int h[], int n, int a, int b) {
    long cnt = 0;
    for (int i=0; i<n; i++) {
        if (h[i] > b*t) {
            cnt += (h[i] - b*t) / (a - b);
            if ((h[i] - b*t) % (a - b) != 0) cnt++;
        }
    }
    return (cnt <= t);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,a,b;
    cin >> n >> a >> b;
    int h[n];
    for (int i=0; i<n; i++) cin >> h[i];

    sort(h, h+n, greater<int>());
    int t = (h[0] / b) / 2;
    int dt = t;
    while (true) {
        bool res = check(t, h, n, a, b);
        if (dt < 2) {
            cout << (res? t : t+1) << endl;
            return 0;
        }
        dt /= 2;
        if (res) {
            t -= dt;
        }
        else {
            t += dt;
        }
    }
}

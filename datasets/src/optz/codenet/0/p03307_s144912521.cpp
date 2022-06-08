#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long int A[200005];

long long int kanashisa(int b) {
    long long int ret = 0;
    for (int i = 0; i < N; i++) {
        ret += abs(A[i]-(b+i+1));
    }
    return ret;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) { cin >> A[i]; }

    long long int high = int(2e9);
    long long int low = int(-2e9);

    int cnt = 0;
    int x = 0;

    while (true) {
        long long int mid = (high+low) / 2;
        long long int a = kanashisa(high);
        long long int b = kanashisa(low);
        long long int c = kanashisa(mid);

        if (a >= b && b <= c) {
            high = mid;
            low = low;
        }
        else if (a >= b && b >= c) {
            high = low;
            low = mid;
        }
        else if (b >= a && a <= c) {
            high = mid;
            low = high;
        }
        else if (b >= a && a >= c) {
            high = high;
            low = mid;
        }

        cnt++;

        if (cnt == 100) {
            x = mid;
            break;
        }
    }
    long long ans;
    for (int i = -100; i <= 100; i++) {
        long long cur = kanashisa(x+i);

        if (i == -100) { ans = cur; }
        else { ans = min(ans, cur); }
    }

    cout << ans << endl;

    return 0;
}
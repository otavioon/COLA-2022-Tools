#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, K;
size_t D;
vector<bool> fav(10, true);
int digit = 1;
int v;

int dfs(int value, int digit)
{
    if (digit == 0) {
        if (value >= N) {
            return value;
        } else {
            // cout << value << endl;
            return -1;
        }
    }

    for (int i = 0; i <= 9; i++) {
        if (fav[i]) {
            int d = dfs(value + i * digit, digit / 10);
            if (d > 0) {
                return d;
            }
        }
    }

    return -1;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> D;
        fav[D] = false;
    }

    while (N / digit > 10) {
        digit *= 10;
    }

    do {
        // cout << "digit : " << digit << endl;
        v = dfs(0, digit);
        digit *= 10;
    } while (v < 0);

    cout << v << endl;
    return 0;
}
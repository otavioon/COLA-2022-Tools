#include<iostream>
using namespace std;
typedef long long LL;

LL top[1000000005];
LL middle[1000000005];
LL bottom[1000000005];

int main() {
    LL N, num, comb = 0;
    cin >> N;
    for (int i = 0; i < 1000000005; i++) {
        top[i] = 0;
        middle[i] = 0;
        bottom[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> num;
        top[num]++;
    }

    for (int i = 0; i < N; i++) {
        cin >> num;
        middle[num]++;
    }

    for (int i = 0; i < N; i++) {
        cin >> num;
        bottom[num]++;
    }

    for (int i = 1; i < 1000000005; i++) top[i] += top[i - 1];
    for (int i = 1000000003; i >= 0; i--) bottom[i] += bottom[i + 1];

    for (int i = 1; i < 1000000005; i++) {
        if (middle[i] != 0) {
            comb += top[i - 1] * middle[i] * bottom[i + 1];
        }
    }

    cout << comb << endl;

    return 0;
}
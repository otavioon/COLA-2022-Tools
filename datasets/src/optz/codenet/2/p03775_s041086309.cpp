#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<long long int, long long int> prime_factor(long long int n) {
    map<long long int, long long int> ret;
    for (long long int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

ll digit(ll n) { return log10(n) + 1; }

int main() {
    ll N;
    cin >> N;

    vector<ll> prime(1, 1);
    map<ll, ll> primes = prime_factor(N);
    for (auto var : primes) {
        for (int i = 0; i < var.second; i++) {
            prime.push_back(var.first);
        }
    }

    ll minimum = digit(N);
    for (int i = 0; i < (1 << prime.size()); i++) {
        bitset<10000> bit1(i);
        ll left = 1;
        ll right = 1;
        for (int j = 0; j < prime.size(); j++) {
            if (bit1[j]) {
                left *= prime[j];
            }
        }
        right = N / left;
        ll tmp;
        tmp = max(digit(right), digit(left));
        if (tmp < minimum) {
            minimum = tmp;
        }
    }

    cout << minimum << endl;

    return 0;
}

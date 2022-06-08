#include <bits/stdc++.h> 
 
#define INF (1<<31) - 1 //INT_MAX/2
#define MOD 1000000007
#define PI  acos(-1)
 
using ll  = long long;
using ull = unsigned long long;

std::vector<ll> enum_div(ll n)
{
    std::vector<ll> ret;
    for (ll i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != 1 && i * i != n) {
                ret.push_back(n/i);
            }
        }
    }

    ret.push_back(n);
    std::sort(ret.begin(), ret.end());

    return ret;
}

ll func(ll N, ll n) {
    int A = 0;
    ll temp = n;
    while (temp > 0) {
        temp /= 10;
        A++;
    }

    int B = 0;
    ll pair = N / n;
    while (pair > 0) {
        pair /= 10;
        B++;
    }

    return std::max(A, B);
}
 
int main(int argc, char *argv[])
{
    ll N;
    std::cin >> N;

    std::vector<ll > ans = enum_div(N);
    ll min = 100000000000;
    for (ll i = 0; i < ans.size(); i++) {
        if (min > func(N, ans[i])) {
            min = func(N, ans[i]);
        }
    }

    std::cout << min << std::endl;

    return 0;
}
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
//#define local
#ifdef local
    #include "dbg-macro/dbg.h"
#endif
//#define hacks
#ifdef hacks
    #include <boost/multiprecision/cpp_int.hpp>
#endif
#define p std::pair
#define ll long long
#define ld long double
#define ull unsigned long long
#define pi std::pair<int, int>
#define stdabs std::abs
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
#define vec std::vector
#define oreq |=
#define npm next_permutation
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);
ll extgcd(ll a, ll b, ll& x, ll& y);
ll nCr(ll n, ll r);
void stat();
template <typename T> T fact(T num);
constexpr ll mod = 1000000000 + 7;
int main()
{
    stat();
int n;cin>>n;
vec<int> b(n-1);
rep(i,n-1){
cin>>b[i];
}
if(n==2){
	cout<<b[0]*2<<endl;return 0;
}
ll ans=0;
for(int i=1;i!=n-1;++i){
ans+=min(b[i],b[i+1]);
}
ans+=(2*b[0])+b[b.size()-1];
cout<<ans<<endl;
    return 0;
}
ll extgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


std::vector<unsigned ll> genprimevec(const unsigned ll N)
{
    std::vector<bool> is_prime(N + 1);
    for (unsigned ll i = 0; i <= N; i++) {
        is_prime[i] = true;
    }
    std::vector<unsigned ll> P;
    for (unsigned ll i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (unsigned ll j = 2 * i; j <= N; j += i) {
                is_prime[j] = false;
            }
            P.emplace_back(i);
        }
    }
    return P;
}

void stat(){
#ifdef local
    rep(i, 2){std::cout << "local enable" << std::endl;
}
#endif
#ifdef hacks
rep(i, 2) { std::cout << "boost enable" << std::endl; }
#endif
}

ll nCr(ll n, ll r)
{
    ll num = 1;
    for (ll i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

template <typename T> T fact(T num)
{
    if (num == 1) { return 1; }
    return num * fact(num - 1);
}

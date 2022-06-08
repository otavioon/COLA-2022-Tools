#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef std::pair<ll,ll> pl;
typedef std::map<string, ll> msl;
typedef std::map<char, ll> mcl;
typedef std::map<ll, ll> mll;
typedef std::vector<ll> vl;
typedef std::vector<pl> vpl;
const ll MOD = 1e9 + 7;
const ll INF = MOD * MOD;
const long double EPS = 1e-9;

ll gcd(ll m, ll n){
    ll a = max(m, n);
    ll b = min(m, n);
    while(b != 1 && b != 0){ a %= b; swap(a, b);}
    return b == 1 ? 1 : a;
}

ll lcm(ll m, ll n){ return m / gcd(m, n) * n;}

ll power_mod(ll a, ll power, ll mod){
    ll value = 1;
    while(power != 0){
        if(power & 1) value = (value * a) % mod;
        a = (a * a) % mod;
        power = power >> 1;
    }
    return value % mod;
}

ll modinv(ll a, ll mod){
    return power_mod(a, mod - 2, mod);
}

ll power_normal(ll a, ll power){
    ll value = 1;
    while(power != 0){
        if(power & 1) value = value * a;
        a = a * a;
        power = power >> 1;
    }
    return value;
}

ll combination(ll n, ll r){
    ll numerator = 1;
    ll denomenator = 1;
    for(ll i = 0; i < r ; i++){
        (numerator *= ll(n - i)) %= MOD;
        (denomenator *= modinv(i + 1, MOD)) %= MOD;
    }
    return (numerator * denomenator) % MOD;
}

ll bin_search(ll key, ll A[], ll left, ll right){
    // return the index idx where A[idx] = key.
    // A[left] is start and A[right] is end..
    while(right >= left){
        ll mid = left + (right - left) / 2;
        if (A[mid] == key) return mid;
        else if (A[mid] > key) right = mid - 1;
        else if (A[mid] < key) left = mid + 1;
    }
    return -1;
}

#define rep(i, n) for(ll (i) = 0; (i) < (n) ; (i)++ )
#define For(i, a, b) for(ll (i) = (a); (i) < (b) ; (i)++ )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define isUpper(c) ('a' - c > 0)
#define toLower(c) char((c)+0x20)
#define toUpper(c) char((c)-0x20)
#define pb push_back
#define mp make_pair
#define pr(a) cout << (a)
#define prl(a) cout << (a) << endl
#define prl2(a,b) cout << (a) << " " << (b) << endl
#define prs(a) cout << (a) << " "
#define yn(condition) if ((condition)) prl("Yes"); else prl("No");
#define YN(condition) if ((condition)) prl("YES"); else prl("NO");
#define rpr(i,n,ans) rep((i),(n)) {if ((i) < n - 1) prs((ans[(i)])); else if ((i) == n - 1) prl((ans[(i)]));}
#define cpr(i,n,ans) rep((i),(n)) prl((ans[(i)]))
#define in1(a) cin >> (a)
#define in2(a,b) cin >> (a) >> (b)
#define in3(a,b,c) cin >> (a) >> (b) >> (c)
#define in4(a,b,c,d) cin >> (a) >> (b) >> (c) >> (d)
#define rin1(i,n,a) rep((i),(n)) cin >> (a[(i)])
#define rin2(i,n,a,b) rep((i),(n)) cin >> (a[(i)]) >> (b[(i)])
#define rin3(i,n,a,b,c) rep((i),(n)) cin >> (a[(i)]) >> (b[(i)]) >> (c[(i)])
#define matin(i,h,j,w,a) rep((i),(h)) rep((j),(w)) cin >> a[i][j]
#define e1 first
#define e2 second
#define ctol(c) ll((c)) - ll('0')
#define ltos(n) to_string((n))
#define items(kv, v) for(auto &(kv): (v))
#define ndig(N, n) ctol(ll(ltos((N))[ll(ltos((N)).length()) - (n)]))
#define beto(a,b,c) (a) < (b) && (b) < (c)
#define betc(a,b,c) (a) <= (b) && (b) <= (c)
#define rsort(a,n) sort(a,a+n,greater<>())
#define Forchar(c,a,z) for(char (c) = (a); (c) <= (z); (c)++)
#define cntchar(s,c) count(all((s)), c)
#define substring(s, start, end) s.substr((start), (end) - (start) + 1)
#define prl_nd(num, digits) cout << fixed << setprecision(digits) << (num) << endl;

const ll MAX_N = 100000;

int main(void){
    ll a, b;
    in2(a,b);

    YN(a * 500 >= b)
    
    return 0;
}
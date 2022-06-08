/* Author : Prasuk Jain */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int              long long int
#define ull              unsigned long long
#define ld               long double
#define fo(i, n)         for(int i=0; i<n; i++)
#define FOR(i, a, b)     for(int i=a; i<b; i++)
#define rfor(i, n)       for(int i=n-1; i>=0; i--)
#define RFOR(i, a, b)    for(int i=b-1; i>=a; i--)
#define tr(it, v)        for(auto it=a.begin(); it!=a.end(); it++)
#define vi               vector<int>
#define pii              pair<int,int>
#define mii              map<int,int>
#define pqb              priority_queue<int>
#define pqs              priority_queue<int,vi,greater<int>>
#define mp               make_pair
#define pb(x)            push_back(x)
#define hcf(x, y)        __gcd(x, y)
#define lcm(x, y)        boost::math::lcm(x,y)
#define setpre(x, y)     fixed << setprecision(y) << x
#define setbits(x)       __builtin_popcountll(x)
#define zerolead(x)      __builtin_clzll(x)
#define zerotrail(x)     __builtin_ctzll(x)
#define all(x)           x.begin(), x.end()
#define sortall(x)       sort(all(x))
#define PI               3.1415926535897932384626
const int mod = 1e9+7;
const int inf = 1e18;
int mpow(int base, int exp);
bool isprime(int num);
void prifact(int num);

//*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!//

void coderprasukj(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int32_t main() {
    //coderprasukj();
    int t, n, k, x, y;
    cin >> k >> x;
    if(500*k>=x) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

//*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!//

int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((int)result * base) % mod;
        base = ((int)base * base) % mod;
        exp >>= 1;
    }
  return result;
}

bool isprime(int num) {
    if(num <= 1) return false;
    for(int i=2; i*i <= num; i++)
        if(num%i == 0) return false;
    return true;
}

void prifact(int num){
    for(int i=2; i<=num; i++)
    if(num%i == 0){
        int cnt = 0;
        while(num%i == 0)
        cnt++ , num /= i;
        cout << i << "^" << cnt << " ";
    }
    if(num > 1)
    cout << num << "^" << "1" << " ";
}

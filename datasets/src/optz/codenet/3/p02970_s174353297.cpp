#include <bits/stdc++.h> 
#define int long long
#define quickie ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rep(i, a, b) for(int i=a; i<b; i++)
#define rep1(i, a, b) for(int i=a; i<=b; i++)
#define repp(i, a, b) for(int i=b-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define db double
#define mi map<int, int>
#define mc map<char, int>
#define ms map<string, int>
#define vi vector<int>
#define qi queue<int>
#define MI(x) power(x, mod-2)
#define test int t; cin >> t;
//#define mod 1000000007LL
#define mod 998244353 
using namespace std;
int power(int x, int y) ;
int gcd(int a, int b) ;

signed main() {
    quickie
    int n, d; 
    cin >> n >> d ;
    int cnt = 0 ;
    for(int i=1; i<=n;) {
        if(i+2*d <= n) {
            i = 1+i+2*d;
            cnt++ ;
        }
        else {
            cnt++ ;
            break ;
        }
    }
    cout << cnt << "\n" ;
}

int power(int x, int y) {
    int res = 1; x %= mod;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res%mod;
}
 
int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

typedef  long long ll;

#define rep(i,a,n) for(ll (i)=(a);(i)<(n);(i)++)
#define rrep(i,a,n) for(ll (i)=(a);(i)>=(n);(i)--)

#define INF ll 1 << 60
#define MOD 1000000007


using namespace std;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int gcd(long long int a,long long int b){
    long long int r;
    if(a < b){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    while(r = a % b){
        a = b;
        b = r;
    }
    return a;
}


void ys(){
    cout << "Yes" << endl;
}

void yb(){
    cout << "YES" << endl;
}

void ns(){
    cout << "No" << endl;
}

void nb(){
    cout << "NO" << endl;
}

int dig(int d){
    int ans = 1;
    if(d == 0) return ans;
    while(d != 0){
        d--;
        ans*=100;
    }
    return ans;
}

ll divisors(ll n) {
    vector<ll> res;

    for(ll i = 1; i*i <= n; ++i) {
        if(n % i != 0) continue;
        res.push_back(i-1);
        if(n/i == i) continue;
        res.push_back((n/i)-1);
    }

    ll ans = 0;

    rep(i,0,res.size()){
        if(res[i] != 0)
        if(n/res[i] == n%res[i]) ans += res[i];
    } 
    return ans;
}

void solve(void){
   int n,i;
   cin >> n >> i;
   cout << n*i - n - i + 1<<endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
vector<long long> calc_divisor(long long n) {//約数列挙
    vector<long long> res;
    for (long long i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            long long j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int keta(ll n){
    int ans = 0;
    while(n>0){
        ans++;
        n/=10;
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    int ans = inf;
    if(calc_divisor(n).size()==1){
        cout<<keta(n)<<endl;
    }else{
        vector<ll> div = calc_divisor(n);
        for(auto u : div){
            int now = max(keta(u),keta(n/u));
            ans = min(now,ans);
        }
        cout << ans << endl;
    }
    return 0;
}
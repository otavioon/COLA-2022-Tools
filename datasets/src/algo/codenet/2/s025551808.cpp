#include <bits/stdc++.h>
#include <bitset>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main(){
    cin>>N;
    multiset<ll> a;
    rep(i,N) cin>>A, a.insert(A);
    ll ans = 0, two = (1LL<<31);
    while(!a.empty()){
        auto ite = a.end();
        --ite;
        ll comp = *ite;
        a.erase(ite);
        while(two > comp * 2) two /= 2;
        ite = a.find(two - comp);
        if(ite != a.end()){
            ++ans;
            a.erase(ite);
        }
    }
    cout<<ans<<endl;
}
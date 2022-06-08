#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string>
#include <numeric>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> vp;
typedef vector<PL> vpl;
typedef vector<vector<P>> vvp;
const int INF = 1001001001;
const ll LINF = 1e18;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define REP(i, n) for(ll i = 0; i < n; i++)
#define FORMAP(it, m) for(auto it = m.begin(); it != m.end(); it++)

template <typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b%a, a);
}
template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

bool p_comp_fs(const P p1, const P p2){ return p1.first < p2.first;};
bool p_comp_fg(const P p1, const P p2){ return p1.first > p2.first;};
bool p_comp_ss(const P p1, const P p2){ return p1.second < p2.second;};
bool p_comp_sg(const P p1, const P p2){ return p1.second > p2.second;};
template <typename T>
vector<T> uniquen(vector<T> vec){
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}


int main(){
    ll N, K; cin >> N >> K;
    vl ds(K, 0); REP(i, K) cin >> ds[i];
    ll ret = 1e5+10;
    REP(i, 100100){
        ll aaaa = i / 1000;
        ll aaa = (i - aaaa * 1000) / 100;
        ll aa = (i - aaaa * 1000 - aaa * 100) / 10;
        ll a = (i - aaaa * 1000 - aaa * 100 - aa * 10);
        bool ok = true;
        if(aaaa != 0)
            ok = ok && find(ds.begin(), ds.end(), aaaa) == ds.end();
        if(aaaa != 0 || aaa != 0)
            ok = ok && find(ds.begin(), ds.end(), aaa) == ds.end();
        if(aaaa != 0 || aaa != 0 || aa != 0)
            ok = ok && find(ds.begin(), ds.end(), aa) == ds.end();
        if(true)
            ok = ok && find(ds.begin(), ds.end(), a) == ds.end();
        if(ok && i >= N){
            ret = i; break;
        }
    }
    cout << ret << endstr;
    return 0;
}

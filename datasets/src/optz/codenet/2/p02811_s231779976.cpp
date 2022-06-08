#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
using Pii = pair<int, int>;
using Pil = pair<int, ll>;
using Pll = pair<ll, ll>;
using Pid = pair<int, ld>;
using Pis = pair<int, string>;
#define rep(i,n) for(int i=0; i<n; i++)
#define repm(i,s,n) for(int i=s; i<n; i++)

const int INF = 1 << 30;
const ll INF_L = 1LL << 60;
const int MOD = 1e9+7; // 998244353;

void cout_ynl(bool b) {cout << (b ? "Yes" : "No") << endl;}
void cout_YNU(bool b) {cout << (b ? "YES" : "NO") << endl;}


// ----------------------------------------------------------------
// String Functions
// ----------------------------------------------------------------
int ctoi(char c){
    if(isdigit(c)) return c - '0';
    else if(islower(c)) return c - 'a';
    else if(isupper(c)) return c - 'A';
    else return -1;
}
char itocd(int i){char c = i+'0'; if(isdigit(c)) return c; else return 0x00;}
char itocl(int i){char c = i+'a'; if(islower(c)) return c; else return 0x00;}
char itocu(int i){char c = i+'A'; if(isupper(c)) return c; else return 0x00;}
// ----------------------------------------------------------------


// ----------------------------------------------------------------
// Dynamical Programming
// ----------------------------------------------------------------
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ----------------------------------------------------------------


// ----------------------------------------------------------------
// Graph Theory
// ----------------------------------------------------------------
vector<vector<int>> adjMat;
vector<set<Pii>> adjList;

void graphDijkstra(){}
void graphBellmanFord(){}
void graphWarshallFloyd(){}
// ----------------------------------------------------------------


// ----------------------------------------------------------------
// Mathematical Functions
// ----------------------------------------------------------------
ll gcd(ll A, ll B) {if (A%B == 0) {return(B);} else {return(gcd(B, A%B));}}
ll lcm(ll A, ll B) {return A * B / gcd(A, B);}
ll divTimes(ll N, ll D) {ll res = 0; while(N%D == 0) {N/=D; res++;} return res;}

ll powMod(ll B, ll P) {
    if(P == 0) return 1;
    if(P%2 == 0){ll t = powMod(B, P/2); return t*t % MOD;}
    return B * powMod(B, P-1) % MOD;
}

/* ----------------------------------
 Factorial, Permutation, Combination
 ---------------------------------- */
const int FAC_INIT_SIZE = 1e6+9;
vector<ll> fac, finv, inv;

void factModInit() {
    fac.resize(FAC_INIT_SIZE);
    finv.resize(FAC_INIT_SIZE);
    inv.resize(FAC_INIT_SIZE);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < FAC_INIT_SIZE; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
ll factMod(ll N){return fac[N] % MOD;}
ll factInvMod(ll N){return finv[N] % MOD;}
ll permMod(ll N, ll K){
    if (N < 0 || K < 0 || N < K) return 0;
    else return factMod(N) * factInvMod(N-K) % MOD;
}
ll combMod(ll N, ll K){
    if (N < 0 || K < 0 || N < K) return 0;
    else if (N < FAC_INIT_SIZE){ return factMod(N) * (factInvMod(K) * factInvMod(N-K) % MOD) % MOD;}
    else {
        ll ans = 1; ll Ks = K < N-K ? K : N-K;
        for (ll i = N; i > N-Ks; i--) {ans *= i; ans %= MOD;}
        return ans * factInvMod(Ks) % MOD;
    }
}

/* ----------------------------------
 Sieve of Atkin & Bernstein
 ---------------------------------- */
vector<bool> sieve;
void sieveInit(ll size){
    sieve.clear();
    if(size < 0 || size > INF) return;
    
    int ss = (int)size+9;
    int ssq = sqrt(ss+0.1);
    sieve.resize(ss);
    sieve[2] = sieve[3] = true;
    
    int n = 0;
    for (int z = 1; z <= 5; z += 4) {
      for (int y = z; y <= ssq; y += 6) {
        for (int x = 1; x <= ssq && (n = 4*x*x+y*y) < ss; x++) sieve[n] = !sieve[n];
        for (int x = y+1; x <= ssq && (n = 3*x*x-y*y) < ss; x += 2) sieve[n] = !sieve[n];
      }
    }
    for (int z = 2; z <= 4; z += 2) {
      for (int y = z; y <= ssq; y += 6) {
        for (int x = 1; x <= ssq && (n = 3*x*x+y*y) < ss; x += 2) sieve[n] = !sieve[n];
        for (int x = y+1; x <= ssq && (n = 3*x*x-y*y) < ss; x += 2) sieve[n] = !sieve[n];
      }
    }
    for (int z = 1; z <= 2; z++) {
        for (int y = 3; y <= ssq; y += 6) {
            for (int x = z; x <= ssq && (n = 4*x*x+y*y) < ss; x += 3) sieve[n] = !sieve[n];
        }
    }
    for (int k = 5; k <= ssq; k++)
      if (sieve[k])
        for (int n = k*k; n < ss; n += k*k) sieve[n] = false;
}

/* ----------------------------------
 Prime Factorization
---------------------------------- */
map<ll, set<ll>> primeFactorSet;
map<ll, map<ll, ll>> primeFactorMap;
void primeFactorInit(){primeFactorMap.clear(); primeFactorSet.clear();}
void primeFactor(ll N){
    if (N < 0 || N > INF_L) return;
    
    ll Nc = N;
    ll Nsq = sqrt(N+0.1);
    set<ll> Nset = {1, N};
    map<ll, ll> Nmap;
    
    for (int k = 2; k <= Nsq; k++) {
        ll dt = 0, d = 1;
        while(Nc%k == 0){
            dt++; d *= k;
            Nset.insert(d);
            Nc /= k;
        }
        if(dt > 0) Nmap[k] = dt;
        if(Nc == 1) break;
    }
    if (Nc != 1) {
        Nmap[Nc] = 1;
        Nset.insert(Nc);
    }
    
    primeFactorSet[N] = Nset;
    primeFactorMap[N] = Nmap;
}
// ----------------------------------------------------------------


void solve() {
    
    int K, X; cin >> K >> X;
    cout_ynl(500*K >= X);
}

int main() {
    
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    solve();
    return 0;
}

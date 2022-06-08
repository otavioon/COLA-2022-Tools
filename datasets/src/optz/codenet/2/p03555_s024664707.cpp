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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<int, ld> Pid;
typedef pair<int, string> Pis;
#define rep(i,n) for(int i=0; i<n; i++)
#define repm(i,s,n) for(int i=s; i<n; i++)
#define all(a) (a).begin(), (a).end()

const int INF = 1 << 30;
const ll INF_L = 1LL << 60;
const int MOD = 1e9+7; // 998244353;

void coi(ll i) {cout << i << endl;}
void cois(ll i) {cout << i << " ";}
void cod(ld d) {cout << fixed << setprecision(16); cout << d << endl;}
void cods(ld d) {cout << fixed << setprecision(16); cout << d << " ";}
void coc(char c) {cout << c << endl;}
void cocs(char c) {cout << c << " ";}
void cos(string s) {cout << s << endl;}
void coss(string s) {cout << s << " ";}
void coynl(bool b) {cos(b ? "Yes" : "No");}
void coYNU(bool b) {cos(b ? "YES" : "NO");}

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
struct edge {ll to, cost;};
struct graph_list {
    ll V;
    vector<vector<edge>> graph;
    vector<ll> dist;
    
    graph_list(ll n){
        init(n);
    }
    void init(ll n){
        V = n;
        graph.resize(V);
        dist.resize(V);
        for (int i = 0; i < V; i++) {dist[i] = INF_L;}
    }
    void add_edge(ll from, ll to, ll cost){
        edge e;
        e.to = to;
        e.cost = cost;
        graph[from].push_back(e);
    }
    
    void dijkstra(ll s){
        for (int i = 0; i < V; i++) {dist[i] = INF_L;}
        dist[s] = 0;
        
        priority_queue<Pll, vector<Pll>, greater<Pll>> que;
        que.push(Pll(0, s));
        while (!que.empty()) {
            Pll p = que.top(); que.pop();
            ll v = p.second;
            if (dist[v] < p.first) continue;
            for (auto e : graph[v]) {
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    que.push(Pll(dist[e.to], e.to));
                }
            }
        }
    }
    void bellman_ford(ll s){
        for (int i = 0; i < V; i++) {dist[i] = INF_L;}
        dist[s] = 0;
        
        /* Under construction */
        
    }
};
struct graph_matrix {
    ll vertex;
    vector<vector<edge>> graph;
    vector<ll> dist;
    
    graph_matrix(ll n){
        init(n);
    }
    void init(ll n){
        vertex = n;
        graph.resize(vertex);
        dist.resize(vertex);
        for (int i = 0; i < vertex; i++) {dist[i] = INF;}
    }
    void add_edge(ll s, ll t, ll cost){
        edge e;
        e.to = t;
        e.cost = cost;
        graph[s].push_back(e);
    }
    
    void warshall_floyd (ll s){
        for (int i = 0; i < vertex; i++) {dist[i] = INF;}
        dist[s] = 0;
        
        /* Under construction */
    }
};
// ----------------------------------------------------------------


// ----------------------------------------------------------------
// Mathematical Functions
// ----------------------------------------------------------------
ll gcd(ll A, ll B) {if(A%B==0){return(B);} else{return(gcd(B, A%B));}}
ll lcm(ll A, ll B) {return A * B / gcd(A, B);}

ll getDigit(ll N) {return (ll)(to_string(N).length());}
ll getDigitForBase(ll N, ll B) {if(B<2){return -1;} else if(B==10){return getDigit(N);} else{ll r=0; while(N!=0){N/=B;r++;} return r;}}
ll getDigitSum(ll N) {ll r=0; string Ns=to_string(N); for(int i=0; i<Ns.length(); i++){r+=ctoi(Ns[i]);} return r;}
ll getDivTimes(ll N, ll D) {ll r=0; while(N%D == 0) {N/=D; r++;} return r;}

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
map<ll, map<ll, ll>> primeFactorMap;
map<ll, set<ll>> primeFactorSet;
void primeFactorizeInit(){primeFactorMap.clear(); primeFactorSet.clear();}
void primeFactorize(ll N){
    if (N < 0 || N > INF_L) return;
    
    ll Nc = N, Nsq = sqrt(N+0.1);
    for (int k = 2; k <= Nsq; k++) {
        ll dt = 0; while(Nc%k == 0) {dt++; Nc /= k;}
        if(dt > 0) primeFactorMap[N][k] = dt;
        if(N%k == 0) {primeFactorSet[N].insert(k); primeFactorSet[N].insert(N/k);}
    }
    if (Nc != 1) primeFactorMap[N][Nc] = 1;
    primeFactorSet[N].insert(1);
    primeFactorSet[N].insert(N);
}
// ----------------------------------------------------------------



//* ****************  GLOBAL VARIABLES  **************** *//

//* **************************************************** *//

void input() {

}

void solve() {
 
    string S[2]; cin >> S[0] >> S[1];
    coYNU(S[0][0] == S[1][2] && S[0][1] == S[1][1] && S[0][2] == S[1][0]);
}

int main() {
    
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    input();
    solve();
    
    return 0;
}

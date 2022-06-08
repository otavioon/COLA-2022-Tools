#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint mod = 1e9 + 7;
#define all(x) (x).begin(), (x).end()
#define fcout cout << fixed << setprecision(15)
inline int bitcount(lint n){ return __builtin_popcountl(n); }
inline int highest(lint n){ return 63 - __builtin_clzl(n); }
inline void YES(bool condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
inline void Yes(bool condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
inline void assert_NO(bool condition){ if(!condition){ cout << "NO" << endl; exit(0); } }
inline void assert_No(bool condition){ if(!condition){ cout << "No" << endl; exit(0); } }
inline void assert_minus_1(bool condition){ if(!condition){ cout << -1 << endl; exit(0); } }
lint power(lint base, lint exponent, lint module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ lint root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position mv[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; // double euclidean(position first, position second){ return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)); }
template<class T, class U> string to_string(pair<T, U> x){ return to_string(x.first) + "," + to_string(x.second); } string to_string(string x){ return x; }
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr first, itr last){ for(auto i = first; i != last; i++){ cin >> (*i); } }
template<class T> T gcd_calc(T a, T b){ if(b){ return gcd_calc(b, a % b); }else{ return a; }}
template<class T> T gcd(T a, T b){ if(a < b) swap(a, b); return gcd_calc(a, b); }
template<class T> T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct combination{ vector<lint> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2, mod); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } lint C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };
template<class itr> bool next_sequence(itr first, itr last, int max_bound){ itr now = last; while(now != first){ now--; (*now)++; if((*now) == max_bound){ (*now) = 0; }else{ return true; } } return false; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b){ if(b < a){ a = b; return 1; } return 0; }
inline int at(int x, int k){ return (x >> k) & 1; }
random_device rnd;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, l, n) for(int i = int(l); i < (n); i++)
#define repr(i, n) for(int i = int(n) - 1; i >= 0; i--)

int N;
vector<int> A_cnt;
vector<vector<int>> roads;
vector<bool> is_came;

int ans = 0;

int ball_pair(int now, int back, int resi){
    is_came[now] = true;
    int ret = min(resi, A_cnt[now]);
    //cout << now << " " << ret << endl;
    ans += ret;
    int next_resi = A_cnt[now] - ret;
    for(int i: roads[now]){
        if(i != back){
            next_resi -= ball_pair(i, now, next_resi);
        }
    }
    return ret;
}

int main(){
    cin >> N;
    map<int, int> A;
    rep(i, N){
        int num;
        cin >> num;
        A[num]++;
    }
    vector<int> A_num;
    for(auto i: A){
        if(bitcount(i.first) == 1){
            ans += i.second / 2 * 2;
            if(i.second % 2){
                A_num.push_back(i.first);
                A_cnt.push_back(1);
            }
        }else{
            A_num.push_back(i.first);
            A_cnt.push_back(i.second);
        }
    }
    int sz = int(A_num.size());
    roads.resize(sz);
    rep(i, sz){
        int opp = (2 << highest(A_num[i])) - A_num[i];
        int pos = int(lower_bound(all(A_num), opp) - A_num.begin());
        if(pos < sz && A_num[pos] == opp && i != pos){
            roads[pos].push_back(i);
            roads[i].push_back(pos);
        }
    }
    //array_output(all(A_num));
    //array_output(all(A_cnt));
    /*rep(i, roads.size()){
        array_output(all(roads[i]));
    }*/
    is_came.resize(N, false);
    repr(i, sz){
        if(!is_came[i]){
            ball_pair(i, -1, 0);
        }
    }
    cout << ans << endl;
}

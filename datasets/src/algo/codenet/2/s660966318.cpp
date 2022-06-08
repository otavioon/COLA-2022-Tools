#include <bits/stdc++.h>

#define int long long

#define pii pair<int, int>

#define x1 x1228
#define y1 y1228

#define left left228
#define right right228

#define pb push_back
#define eb emplace_back

#define mp make_pair 

#define ff first
#define ss second   

#define matr vector<vector<int> > 

#define all(x) x.begin(), x.end()


using namespace std;
typedef long long ll; 
typedef long double ld; 

const int maxn = 3e5 + 7, mod = 1e9 + 7, inf = 1e18, MAXN = 1e6 + 7;
const double eps = 1e-9;
mt19937 rnd(time(0));
int n; 
int cnt[maxn]; 
multiset<int> p;
         
void solve() {        
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        p.insert(a); 
    }
    int ans = 0;
    while (p.size()) {
        int d = *(--p.end());
        p.erase(--p.end());
        for (int pt = 1; pt <= 2e9; pt *= 2) {
            int k = pt - d; 
            if (p.find(k) != p.end()) {
                ++ans;
                p.erase(p.find(k)); 
                break; 
            }
        }        
    }
    cout << ans; 
}                               
   
signed main() {
#ifdef LOCAL
    freopen("TASK.in", "r", stdin);
    freopen("TASK.out", "w", stdout);
#else 
    
#endif // LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20); 
    cout << fixed; 
    int t = 1;  
    for (int i = 0; i < t; ++i)              
        solve();
    return 0;
}  
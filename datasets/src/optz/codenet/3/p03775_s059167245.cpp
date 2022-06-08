#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> dd;
    for(ll i = 1; i*i <= N; i++){
        if(N % i == 0){
            dd.push_back(i);
            if(i * i != N){
                dd.push_back(N/i);
            }
        }
    }
    sort(dd.begin(), dd.end());
    ll f_min = 1e9;
    rep(i,0,dd.size()){
        ll l1 = to_string(dd[i]).size();
        ll l2 = to_string(N/dd[i]).size();
        f_min = min(f_min, max(l1,l2));
    }
    print(f_min);

}

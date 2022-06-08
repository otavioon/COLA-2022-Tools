#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

ll solveA(){
    ll res = 0;
    ll A,B; cin >> A >> B;
    res = A*B - A - B + 1;
    return res;
}


ll solveB(){
    ll res = 0;
    ll N; cin >> N;
    if(N>=105) res++;
    return res;
}

ll solveC(){
    ll res = 0;
    string S; cin >> S; ll K; cin >> K;
    res = 1;
    for(int i = 0; S.length();i++){
        if(S[i] == '1') continue;
        else{
            res = S[i] - '0';
            break;
        }
    }
    return res;
}

ll solveD(){
    ll res = 0;
    ll N,M,Q; cin >> N >> M >> Q;
    vector<ll> L(M),R(M);
    vector<vector<ll>> G(N);
    for(int i = 0; i < M;i++){
        cin >> L[i] >> R[i]; L[i]--; R[i]--;
        G[L[i]].push_back(R[i]);
    }
    for(int i = 0; i < N;i++){
        sort(G[i].begin(),G[i].end());
    }
    while(Q--){
        ll p,q; cin >> p >> q;
        p--; q--;
        
        ll Ans = 0;
        for(ll x = p; x <= q;x++){
            Ans += (upper_bound(G[x].begin(), G[x].end(), q) - G[x].begin());
        }
        cout << Ans << endl;
    }
    return 0;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solveA() << endl;
    //cout << solveB() << endl;
    //cout << solveC() << endl;
    //solveD();
    return 0;
}

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define REP(i,s,n) for(int i=s; i<(n); ++i)
#define ALL(n) begin(n),end(n)
using ll = long long;
const ll INF = 1e18;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    REP(i, 0, N) cin >> A[i];
    REP(i, 0, N) cin >> B[i];
    REP(i, 0, N) cin >> C[i];
    sort(ALL(A));
    sort(ALL(B));
    sort(ALL(C));

    // 解答の方針はよかったが，TLEやREしないようにするにはupperboundのSTLを活用することが大事だった…

    // Cのとりうる範囲内で，ある数以上になっている数の個数をカウントしてvectorに収納
    // int C_max = C[N - 1];
    // vector<int> C_upper_cnt(C_max + 1);
    // REP(i, 0, N){
    //     chmax(C_upper_cnt[C[i]], N - i);
    // }
    // int Ctmp = 0;
    // for (int i = C_max; i >= 0; --i){  // 直接C内になかった値のインデックス部分は0になってるので右側の値で埋めてやる
    //     if (!chmax(Ctmp, C_upper_cnt[i])){
    //         C_upper_cnt[i] = Ctmp;
    //     }
    // }
    vector<ll> d(N);
    REP(i, 0, N){
        d[i] = (ll)(C.size() - (upper_bound(ALL(C), B[i]) - C.begin()));
    }

    // 各Bの値について，その数以上のBを選択したときのCの候補数の総和
    // int B_max = B[N - 1];
    // vector<ll> B_upper_cnt(B_max + 1);
    // ll C_cnt = 0;
    // for (int i = N - 1; i >= 0; --i){
    //     if (B[i] + 1 > C_max) continue;
    //     C_cnt += C_upper_cnt[B[i] + 1];  //「以上」から「より大きい」に注意
    //     B_upper_cnt[B[i]] = C_cnt;
    // }
    // ll Btmp = 0;
    // for (int i = B_max; i >= 0; --i){
    //     if (!chmax(Btmp, B_upper_cnt[i])){
    //         B_upper_cnt[i] = Btmp;
    //     }
    // }
    for(int i=N-2; i>=0; i--) d[i] += d[i+1];

    ll ans = 0;
    // REP(i, 0, N){
    //     if (A[i] + 1 > B_max) break;
    //     ans += B_upper_cnt[A[i] + 1];  //「以上」から「より大きい」に注意
    // }
    REP(i, 0, N){
        int t = upper_bound(ALL(B), A[i]) - B.begin();
        if(t<N) ans += (ll)d[t];
    }
    cout << ans << endl;

    return 0;
}

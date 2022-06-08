#include <bits/stdc++.h>

#include <math.h>
#include <stdlib.h>


#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true; } return false; }

//INT_MAX	2,147,483,647 = 2*1.0e9

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int N; cin >> N;
    vector<int> A(N), B(N), C(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());

    vector<int> Bcnt(N);
    int pos = 0;
    for(int i = 0; i < N; i++){
        while(B[i] < C[pos] && pos < N) pos++;
        Bcnt[i] = pos;
    }
    
    vector<int> sum(N+1);
    for(int i = 1; i < N+1; i++) sum[i] = sum[i-1] + Bcnt[i-1];

    ll ans = 0;
    pos = 0;
    for(int i = 0; i < N; i++){
        while(A[i] < B[pos] && pos < N) pos++;
        ans += (ll)sum[pos];
    }
    cout << ans << endl;

    return 0;
}

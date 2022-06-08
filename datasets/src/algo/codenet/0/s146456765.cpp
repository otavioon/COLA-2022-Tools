#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
const int INF = 1e8;

int main(){
    string S; Int K;
    cin >> S >> K;

    Int N = S.size();
    Int ans = 0;
    
    if(S[0] == S[N-1]){
        Int id = N-1;
        while (S[id] == S[0] && id > 0) id--;
        id++;
        S = S.substr(id) + S.substr(0, id);
    }

    if(S[0] == S[N-1]){
        if(N % 2 == 0) cout << N/2 * K << endl;
        else cout << N * (K/2) + (N/2) * (K%2)  << endl;
        return 0;
    }

    rep(i,N-1){
        if(S[i+1] == S[i]){
            S[i+1] = '0';
            ans++;
        }
    }
    ans *= K;
    cout << S << endl;
    cout << ans << endl;
}

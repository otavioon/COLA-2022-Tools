#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int ans = 0;
    map<string, int> blue;
    rep(i, N){
        string S; cin >> S;
        blue[S]++;
    }
    vector<string> red;
    int M; cin >> M;
    rep(i, M){
        string S; cin >> S;
        red.push_back(S);
    }
    for(auto op: blue){
        string S = op.first;
        int num = op.second;
        int r = 0;
        rep(i, M) if(S == red[i]) r++;
        ans = max(ans, num-r);
    }
    cout << ans << endl;
    return 0;
}
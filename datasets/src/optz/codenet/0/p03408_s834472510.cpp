#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> Pint;
typedef pair<ll, ll> P;
//typedef pair<int, pair<int, int>> P;
//typedef tuple<int,int,int> T;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2147483600;//10^9
ll MOD  = 1000000007;
vector<int> dy = {0,0,1,-1};
vector<int> dx = {1,-1,0,0};

int main(void){
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    int M;
    cin >> M;
    vector<string> T(M);
    for(int i = 0; i < M; i++) cin >> T[i];
    
    int ans = 0;
    for(int i = 0; i < N; i++){
        int res = 0;
        for(int j = 0; j < N; j++){
            if(S[i] == S[j]) res++;
        }
        for(int j = 0; j < M; j++){
            if(S[i] == T[j]) res--;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}


#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int N;
long A[MAX_N], B[MAX_N], C[MAX_N];

void solve(){
    long BS[MAX_N];
    for(int i = 0; i < N; i++){
        int n = distance(C, upper_bound(C, C + N, B[i]));
        BS[i] = N - n;
    }
    long BSS[MAX_N];
    for(int i = N - 1; i >= 0; i--){
        if (i == N - 1) {
            BSS[i] = BS[i];
            continue;
        }
        BSS[i] = BS[i] + BSS[i + 1];
    }
    long ans = 0;
    for(int i = 0; i < N; i++){
        int n = distance(B, upper_bound(B, B + N, A[i]));
        ans += BSS[n];
    }
    cout << ans << endl;
    return;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    sort(A, A + N);
    sort(B, B + N);
    sort(C, C + N);
    solve();
    return 0;
}
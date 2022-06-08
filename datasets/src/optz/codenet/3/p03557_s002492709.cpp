#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> A(N), B(N), C(N);
    // A = B = C = v;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    // for(int i = 0; i < N; i++) cout << A[i] << ' ';
    // cout << endl;
    // for(int i = 0; i < N; i++) cout << B[i] << ' ';
    // cout << endl;
    // for(int i = 0; i < N; i++) cout << C[i] << ' ';
    // cout << endl;

    long long ans = 0;
    for(int i = 0; i < N; i++){
        int tmp1 = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        // if(tmp1 == B[i]) tmp1--;
        int tmp2 = upper_bound(C.begin(), C.end(), B[i]) - C.begin();
        // if(tmp2 == C[i]) tmp2--;
        ans += tmp1 * (N-tmp2);
        // cout << tmp1 * (N-tmp2) <<endl;
    }
    cout << ans << endl;

    return 0;
}

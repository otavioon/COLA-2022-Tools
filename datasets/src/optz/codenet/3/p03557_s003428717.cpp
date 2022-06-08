#include <bits/stdc++.h>
using namespace std;
#define ll long long

typedef pair<int,int> P;

int main(){
    int n;
    cin >> n;
    vector<ll>A(n), B(n), C(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int i = 0; i < n; i++) cin >> C[i];
    sort(B.begin(),B.end()); sort(C.begin(),C.end());
    vector<ll>a_lower(n), b_lower(n);
    for (int i = 0; i < n; i++){
        a_lower[i] = B.end() - upper_bound(B.begin(), B.end(), A[i]);
    }
    for (int i = 0; i < n; i++){
        b_lower[i] = C.end() - upper_bound(C.begin(), C.end(), B[i]);
    }
    vector<ll>b_sum(n+1);
    for (int i = 1; i <= n; i++){
        b_sum[i] = b_sum[i-1] + b_lower[n-i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += b_sum[a_lower[i]];
    }
    cout << ans << "\n";
}
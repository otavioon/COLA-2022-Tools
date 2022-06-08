#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define FOR(i, m, n) for(ll i = m; i < (n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>; 
using vl = vector<ll>;
using vll = vector<vl>;
using pll = pair<ll, ll>;


int main() {
    int N;
    cin>>N;
    vector<long> A(N);
    vector<long> B(N);
    vector<long> C(N);
    for(int i=0;i<N;++i){
        cin>>A[i];
    }
    for(int i=0;i<N;++i){
        cin>>B[i];
    }
    for(int i=0;i<N;++i){
        cin>>C[i];
    }
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());
    long ans = 0;
    long a, c;
    for(int i=0;i<N;++i){
        a = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        c = C.end() - upper_bound(C.begin(), C.end(), B[i]);
        ans += a*c;
    }
    cout<<ans<<endl;
}
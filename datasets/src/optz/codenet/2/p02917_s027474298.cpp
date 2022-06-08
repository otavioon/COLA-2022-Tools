#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
    int N;
    cin >> N;
    vector<int> B(N-1, 0);
    rep(i,N-1) {
        cin >> B.at(i);
    }
    
    vector<int> A(N, 0);
    rep(i,N-1) {
        if (i == 0) A.at(i) = B.at(i);
        else {
            A.at(i) = min(B.at(i-1), B.at(i));
        }
    }
    A.at(N-1) = B.at(N-2);
    int ans = 0;
    rep(i,N) ans += A.at(i);
    cout << ans << endl;
    
    return 0;
}
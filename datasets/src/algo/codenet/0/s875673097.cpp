#include <iostream>
typedef long long ll;
using namespace std;

ll sol(string S, int N, int K) {
    ll ans = 0;
    // no need to check 1st character
    for(int i=1; i<N; i++) { 
        if(i==N-1 && S[i]==S[i-1]) ans += 1;
        else if(S[i]==S[i-1]) {
            ans += 1;
            i++;    // skip next character (as it's already checked)
        }
    }
    ans *= K;
    return ans;
}

int main() {
    string S;
    int N;
    ll K;
    cin >> S >> K;
    N = S.size();

    cout << sol(S, N, K) << endl;
}
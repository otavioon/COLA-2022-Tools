#include <iostream>
typedef long long ll;
using namespace std;

ll sol(string S, int N, int K) {
    ll ans = 0;
    
    if(N==1) {  // only 1 char in string
        ans = K/2;  // works for length of T is even and odd
        return ans;
    }
    for(int i=1; i<N; i++) {    // no need to check 1st char
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
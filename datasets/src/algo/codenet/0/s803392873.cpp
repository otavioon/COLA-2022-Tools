#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    string S;
    ll K;
    cin >> S >> K;
    ll out = 0;
    ll N = S.length();
    rep(i,N-1){
        if(i==0&&S[0]==S[N-1]){
            ll cnt = 1;
            for(ll j=1;j<N-1;j++){
                if(S[j]==S[0]) cnt++;
            }
            if(cnt==N-1) out = N*K/2;
            else out += cnt/2 + (K-1)*((cnt+1)/2);
            i += cnt-1;
        }else if(S[i]==S[i+1]){
            out += K;
            i++;
        }
    }
    cout << out << endl;
    return 0;
}

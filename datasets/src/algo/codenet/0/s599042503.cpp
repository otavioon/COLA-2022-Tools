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
    rep(i,N){
        if(i==N-1&&S[0]==S[N-1]){
            out += K-1;
            if(S[0]==S[1]) out -= K-1;
        }else if(S[i]==S[i+1]){
            out += K;
            i++;
        }
    }
    rep(i,N){
        ll cnt = 0;
        if(S[i]==S[i+1]) cnt++;
        if(cnt==N-1) out = N*K/2;
    }
    cout << out << endl;
    return 0;
}

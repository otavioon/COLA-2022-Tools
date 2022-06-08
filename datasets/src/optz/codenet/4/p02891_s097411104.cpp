#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9+7;

int main(void) {

    string S; cin >> S;
    ll K; cin >> K;
    set<char> S_set;

    ll S_duplication = 0;
    for (int i = 0; i < S.size()-1; ++i) {
        if(S[i]==S[i+1]){
            S_duplication++; i++;
        }
    }
    for (int i = 0; i < S.size(); ++i) {
        S_set.insert(S[i]);
    }

    if(S_set.size() == 1){
        cout<<(S.size()*K)/2<<endl;
    } else if(S[0]!=S[S.size()-1]){

        cout<<S_duplication*K<<endl;

    } else{
        ll a=0;
        for (int i = 0; i < S.size(); ++i) {
            if(S[0]!=S[i]) {break;}
            a++;
        }
        ll b=0;
        for (int i = S.size()-1; i > a; --i) {
            if(S[0]!=S[i]){break;}
            b++;
        }

        ll ans = S_duplication*K - ((a/2+b/2)-(a+b)/2)*(K-1);
        cout<<ans<<endl;
    }

    return 0;
}
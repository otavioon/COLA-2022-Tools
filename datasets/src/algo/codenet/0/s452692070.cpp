#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9+7;

int main(void){

    string S; cin>>S;
    ll K; cin>>K;



    string S2 = S+S;

    ll cntS1 = 0,cntS2 = 0;
    for (int i = 1; i < S2.size(); ++i) {
        if(S2[i-1]==S2[i]){
            (i+1<=S.size())?cntS1++:cntS2++;
            i++;
        }
    }

    ll renketusuu = 1;
    for (int i = 1; i < S.size(); ++i) if(S[0]==S[i]) renketusuu++;
    for (int i = S.size()-1; i>0 ; --i) if(S[0]==S[i]) renketusuu++;

    // 文字が一文字のとき
    if(S.size()==1){
        cout<<K/2<<endl;
    }else if(renketusuu%2!=0){
        ll ans = cntS1*ceil((double)K/2)+cntS2*floor((double)K/2);
        cout<<ans<<endl;
    }else{
        cout<<cntS1*K<<endl;
    }

    return 0;
}
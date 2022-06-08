//Alhamdulillah
//Md. Masrur Saqib-RUET-1803
//Created on 06-09-2019 11.30

#include<bits/stdc++.h>
#define ll unsigned long long
#define pb push_back

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;
    ll K,count = 0;
    cin >> K;
    ll nn = S.size();
    for(ll i = 1; i<nn; i++){
        if(S[i] == S[i - 1]){
            count++;
            i++;
        }
    }
    ll k = 0;
    if(S[0] == S[nn-1]){
            if(S[0] != S[nn - 2]){
                k++;
            }
        }
    ll mas = count * K;
    if(k){
        mas += (K-1);
    }
    if(S[0] == S[1]){
                mas -= (K-1);
        }
        if(S[0] == S[1] && S[0] == S[nn-1] && S[0]== S[nn - 2]){
            mas+= (K-1);
        }


    printf("%llu\n",mas);

    return 0;
}

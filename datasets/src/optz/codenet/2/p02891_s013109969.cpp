#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    string S;cin>>S;
    ll K;cin>>K;
    ll N=S.size();
    vector<ll> c;
    char a=S.at(0);ll count=0;
    for(int i=0;i<N;i++){
        if(a==S.at(i)){
            count++;
            if(i==N-1){
                c.push_back(count);
                break;
            }
        }
        else{
            c.push_back(count);
            count=0;
            a=S.at(i);
            i--;
        }
    }
    int cs=c.size();
    if(cs==1){
        cout<<ll(N*K/2)<<endl;
        return 0;
    }
    if(S.at(0)!=S.at(N-1)){
        ll ans=0;
        for(int i=0;i<cs;i++){
            ans+=c.at(i)/2;
        }
        ans*=K;
        cout<<ans<<endl;
    }
    else{
        ll p=c.at(cs-1);
        c.at(cs-1)+=c.at(0);
        ll ans=0;
        for(int i=1;i<cs;i++){
            ans+=c.at(i)/2;
        }
        ans*=K-1;
        for(int i=0;i<cs-1;i++){
            ans+=c.at(i)/2;
        }
        ans+=p/2;
        cout<<ans<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>

int main(){
    using ll = long long;
    int K;
    std::string s;
    std::cin>>s>>K;
    if(s.size()==1){
        std::cout<<K/2<<"\n";
        return 0;
    }
    ll dp[32]={};
    bool bk=true;
    for(int i=0;i+1<s.size();++i){
        if(s[i]==s[i+1]){
            dp[0]++;
            i++;
            if(i+1==s.size()) bk = false;
        }
    }
    if(s.front()!=s.back()) bk = false;
    ll ans=0;
    for(int i=0;i<32;++i){
        if(i<31) dp[i+1] = 2*dp[i] + bk;
        if(K>>i&1) ans += dp[i] + bk;
    }
    std::cout<<ans<<"\n";
}

#include<bits/stdc++.h>
#define endl enjoy_codeforces
using lint=long long;
int main(){
    std::cin.tie(nullptr);std::ios_base::sync_with_stdio(false);
    int n;std::cin>>n;
    std::multiset<int,std::greater<>>a;
    while(n--){
        int x;std::cin>>x;
        a.insert(x);
    }
    int ans=0;
    while(!a.empty()){
        int x=*a.begin();a.erase(a.begin());
        int y=1;while(y<=x)y*=2;
        y-=x;
        auto it=a.lower_bound(y);
        if(it==a.end())continue;
        ans++;
        a.erase(it);
    }
    std::cout<<ans<<'\n';
}

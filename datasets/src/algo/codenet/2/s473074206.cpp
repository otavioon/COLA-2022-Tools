#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MN = 2e5+5;
multiset<int> arr;
int n, i, j, ans;

signed main(){
    for(scanf("%lld",&n),i=1;i<=n;i++){
        int x; scanf("%lld",&x);
        arr.insert(x);
    }
    while(arr.size()){
        auto it = arr.end(); it--;
        int cur = *it; arr.erase(it);
        for(i=0;(1LL<<i)<=cur;i++){}
        int rem = (1LL<<i)-cur;
        if(arr.find(rem)!=arr.end()){
            ans++;
            arr.erase(arr.find(rem));
        }
    }
    printf("%lld\n",ans);
    return 0;
}

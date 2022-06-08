typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    ll a[200000+1];
    ll result = 0;
    std::cin >> n;
    std::unordered_map<ll, ll> v;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        v[a[i]]=1;
    }
    sort(a,a+n,greater<>());
    
    for (int i = 0; i < n; i++) {
        if(v[pow(2,floor(log2(a[i]))+1)-a[i]]==1){
            if(a[i] == pow(2,float(log2(a[i]))+1)-a[i]) continue;
            v[pow(2,floor(log2(a[i]))+1)-a[i]]=0;
            result++;
        }else{
            
        }
    }
    std::cout << result << std::endl;
}

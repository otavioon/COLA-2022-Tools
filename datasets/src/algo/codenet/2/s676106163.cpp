#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAX_N = 2*1e5+100;
int n;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    LL x;
    multiset<LL> s;
    for(int i = 0; i < n; ++i){
        cin >> x;
        s.insert(x);
    }
    int ans = 0;
    while(!s.empty()){
        LL x = *s.rbegin();
        s.erase(s.find(x));
        LL now = 1LL;
        while(now <= x) now <<= 1;
        auto it = s.find(now - x);
        if(it == s.end()) continue;
        s.erase(it);
        ++ans;
    }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int getpair(int v){
    int res = 1;
    while(res <= v) res *= 2;
    return res - v;
}

int main(){
    int n, a;
    cin >> n;
    multiset<int> ms;
    rep(_, n){
        scanf("%d", &a);
        ms.insert(a);
    }
    int cnt = 0;
    while(!ms.empty()){
        auto maxv = end(ms);
        ms.erase(--maxv);
        auto p = ms.find(getpair(*maxv));
        if(p != end(ms)){
            ms.erase(p);
            cnt++;
        }
    }
    cout << cnt << "\n";
}
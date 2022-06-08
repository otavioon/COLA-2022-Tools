#include <bits/stdc++.h>
using namespace std;
int N, ans,a;
multiset<int> S;
int main(){
    cin>>N;
    for (int i=1; i<=N; i++) {
        scanf("%d", &a);
        S.insert(a);
    }
    while (!S.empty()){
        int t = *(--S.end()), k;
        S.erase(--S.end());
        for (k=1; k<=t; k<<=1);
        if (S.find(k-t) != S.end()){
            ans++;
            S.erase(S.find(k-t));
        }
    }
    cout<<ans;
    return 0;
}
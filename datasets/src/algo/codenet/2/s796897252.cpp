#include <bits/stdc++.h>
using namespace std;

int N, ans;
multiset<int> S;

int main(){
    int a;
    scanf("%d", &N);
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
    printf("%d\n", ans);
    return 0;
}

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> L(N);
    for(int i = 0;i < N;++i){
        cin >> L[i];
    }
    sort(L.begin(),L.end());
    ll ans = 0;
    for(int i = 0;i < N-2;++i){
        for(int j = i+1;j < N-1;++j){
            for(int k = j+1;k < N;++k){
                int a = L[i];
                int b = L[j];
                int c = L[k];
                if(c < a + b) ans++;
            }
        }
    }
    cout << ans << endl;
}
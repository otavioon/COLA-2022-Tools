#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> L(N);
    for(int i = 0; i < N; i++){
        cin >> L[i];
    }
    sort(L.begin(), L.end());
    int ans = 0;
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            auto it = lower_bound(L.begin() + j + 1, L.end(), L[i] + L[j]);
            ans += it - (L.begin() + j + 1);
        }
    }
    cout << ans << endl;
}
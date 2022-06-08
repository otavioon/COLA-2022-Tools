#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    int ans;ans=0;
    vector<int> L(N);
    for(int i=0;i<N;i++) {
        cin >> L[i];
    }
    sort(L.begin(),L.end());
    for(int i=0;i<N-2;i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                if (L[k] < (L[i] + L[j])) {
                    ans = ans + 1;
                } else {
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
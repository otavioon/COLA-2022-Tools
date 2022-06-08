#include <bits/stdc++.h>

constexpr unsigned long opposite(unsigned long v){
    return (~(~0 << 64 - __builtin_clzl(v)) ^ v) + 1;
}

int main(){
    using namespace std;

    unsigned long N;
    cin >> N;
    vector<pair<unsigned long, bool>> A(N, {0, 1});
    for(auto& i : A)cin >> i.first;
    sort(A.rbegin(), A.rend());
    unsigned long ans{0};
    for(const auto& i : A){
        if(i.second && binary_search(A.rbegin(), A.rend(), pair<unsigned long, bool>({opposite(i.first), 1}))) {
            A[A.rend() - upper_bound(A.rbegin(), A.rend(), pair<unsigned long, bool>({opposite(i.first), 1}))].second = false;
            ++ans;
        }
    }
    cout << ans << endl;
}
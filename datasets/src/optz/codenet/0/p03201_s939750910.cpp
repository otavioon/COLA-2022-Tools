#include <bits/stdc++.h>

constexpr unsigned long opposite(unsigned long v){
    return (~(~0LL << 64 - __builtin_clzl(v)) ^ v) + 1;
}

int main(){
    using namespace std;

    unsigned long N;
    cin >> N;
    deque<pair<unsigned long, bool>> A(N, {0, 1});
    for(auto& i : A)cin >> i.first;
    sort(A.begin(), A.end());

    unsigned long ans{0};
    auto i = A.back();
    for(A.pop_back(); !A.empty(); i = A.back(), A.pop_back())if(i.second && binary_search(A.begin(), A.end(), pair<unsigned long, bool>({opposite(i.first), 1})) && ++ans)A[lower_bound(A.begin(), A.end(), pair<unsigned long, bool>({opposite(i.first), 1})) - A.begin()].second = false;

    cout << ans << endl;
}
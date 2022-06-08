#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long N;
    cin >> N;
    vector<unsigned long> L;
    L.reserve(N);
    copy_n(istream_iterator<unsigned long>(cin), N, back_inserter(L));
    unsigned long ans{0};
    for(unsigned long i = 2; i < N; ++i)for(unsigned long j = 1; j < i; ++j)for(unsigned long k = 0; k < j; ++k)if(L[i] < L[j] + L[k])if(L[j] < L[i] + L[k] && L[k] < L[i] + L[j])++ans;
    cout << ans << endl;
    return 0;
}
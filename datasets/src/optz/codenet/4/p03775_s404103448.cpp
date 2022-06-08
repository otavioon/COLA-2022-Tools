#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll N;
    cin >> N;
    set<ll> A;
    for(ll i=1;i<=N/i;i++)if(N%i==0)A.insert(max(to_string(i).size(),to_string(N/i).size()));
    cout << *A.begin() << endl;
}

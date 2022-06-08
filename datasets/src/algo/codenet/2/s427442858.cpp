#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    multiset<ll> A;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A.insert(a);
    }
    
    int ans = 0;
    while (!A.empty()) {
        auto it = A.end();
        it--;
        ll t = 1;
        while (t <= (*it)) t *= 2;
        auto it2 = A.find(t-(*it));
        if (it2 != it && it2 != A.end() && (*it)+(*it2) == t) {
            ans++;
            A.erase(it2);
            it = A.end();
            it--;
            A.erase(it);
        }
        else {
            A.erase(it);
        }
    }
    cout << ans << endl;
    return 0;
}
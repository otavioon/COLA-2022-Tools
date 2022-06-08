#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
const int MOD = 1e9 + 7;
const int INF = 9e18;

signed main(){
    int N;
    cin >> N;
    multiset<int> A;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.insert(temp);
    }
    int ans = 0;
    while (!A.empty()) {
        int base, key;
        {
            auto itr = A.end();
            --itr;
            base = *itr;
            int count = 0;
            int k = base;
            while (k > 0) {
                k /= 2;
                ++count;
            }
            key = (1<<count) - base;
            A.erase(itr);
        }
        auto itr = A.find(key);
        if (itr != A.end()) {
            A.erase(itr);
            ++ans;
        }
    }
    cout << ans << endl;
}
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
 
using namespace std;
 
const int MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;
#define rep(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)
 
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, 0, N){
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    rep(i, 0, N) {
        ans += abs(a[i] - a[N/2]);
    }
    cout << ans << endl;
}
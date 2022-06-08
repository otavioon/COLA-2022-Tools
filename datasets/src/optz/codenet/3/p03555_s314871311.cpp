#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007


int main(void){

    int n;
    cin >> n;

    ll a[n], b[n], c[n];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    //昇順にソート
    sort(a, a+n+1);
    sort(c,c+n+1);

    int ans = 0;
    //配列bを基準に、bより小さい&&bより大きい個数を掛け算で加算
    rep(i,n){
        //b[l]よりも小さい数を求める
        int temp_l = lower_bound(a, a + n, b[i]) - a;

        //b[l]よりも大きい数を求める
        int temp_r = upper_bound(c, c + n, b[temp_l]) - c;

        ans += temp_l*(n-temp_r);
    }
    cout << ans << endl;

    return 0;
}

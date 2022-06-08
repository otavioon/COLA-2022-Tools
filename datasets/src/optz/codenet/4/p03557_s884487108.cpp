#define _GLIBCXX_DEBUG
#include"bits/stdc++.h"

using namespace std;

//input
template <class T> T get(){ T s; cin >> s; return(s);}
#define gi get<int>()
#define gs get<string>()

void Main() {
    //code here
    int n;
    cin >> n;
    vector<int> as(n), bs(n), cs(n);
    for (int i = 0; i < n; i++) cin >> as[i];
    for (int i = 0; i < n; i++) cin >> bs[i];
    for (int i = 0; i < n; i++) cin >> cs[i];
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    sort(cs.begin(), cs.end());
    //print(as);print(bs);print(cs);
    int res = 0;
    for (int b: bs) {
        int a_count = lower_bound(as.begin(), as.end(), b) - as.begin();
        int c_count = cs.end() - upper_bound(cs.begin(), cs.end(), b);
        //print(c_count);
        res += c_count * a_count;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Main();
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int bs_maxIdx(int array[], int len, int tar){
    int lower = 0;
    int upper = len - 1;
    
    while(lower < upper){
        int mid = (lower + upper)/2;
        if(array[mid] < tar){
            lower = mid+1;
        }else{
            upper = mid-1;
        }
        // cout << mid << "," << array[mid] << endl;
    }
    // cout << "l = " << lower << ", u = " << upper << endl;
    int idx;
    for(idx = lower; idx < len; ++idx){
        if(array[idx] > tar) break;
    }
    return idx;
}

int main() {
    int n;
    cin >> n;
    
    int a[n], b[n], c[n];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    
    sort(a, a+n);
    sort(b, b+n);
    sort(c, c+n);
    
    ll res = 0;
    rep(i, n){
        int start_b = bs_maxIdx(b, n, a[i]);
        for(int j = start_b; j < n; ++j){
            res += n - bs_maxIdx(c, n, b[j]);
        }
    }
    
    cout << res << endl;
    return 0;
}
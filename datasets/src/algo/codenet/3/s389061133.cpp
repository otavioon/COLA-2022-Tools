#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    long n,ans=0;
    cin >> n;
    int a[n],b[n],c[n];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    rep(i,n){
        long d,e;
        int ng=-1,ok=n;
        while(ok-ng>1){
            int mid = ok-(ok-ng)/2;
            if(b[i]<c[mid]) ok = mid;
            else ng = mid;
        }
        d = n-ok;
        ng = n;
        ok = -1;
        while(ng-ok>1){
            int mid = ng - (ng-ok)/2;
            if(a[mid]<b[i]) ok = mid;
            else ng = mid;
        }
        e = ok+1;
        ans += d*e;
    }
    cout << ans << endl;
}
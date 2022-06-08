#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d, e;
    cin >> n >> d;
    int ans = 1;
    int f = 0;
    for(int i = 0; i < n; i++) {
        if( f != 0){
            e = f + 1 + d;
        }
        else e = d + 1 + d;
        if (e >= n) {
            break;
        }
        else ans++;
        f = e;
    }
    cout << ans << endl;
}
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll a[n], b[n], c[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) cin >> c[i];

    sort(a, a+n); sort(b, b+n); sort(c, c+n);

    ll cnt=0;
    for(int i=n-1; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {
            if(a[i]>=b[j]) break;
            for(int k=n-1; k>=0; k--) {
                if(b[j]>=c[k]) break;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

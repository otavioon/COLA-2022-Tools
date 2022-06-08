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

    ll cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(a[i]>=b[j]) continue;
            for(int k=0; k<n; k++) {
                if(b[j]>=c[k]) continue;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

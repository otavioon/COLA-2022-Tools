#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
 
/* bool cmp(int a, int b) {
    return a > b;
}*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n] , b[n] , c[n];
    for( int i = 0 ; i < n ; i++ ) cin >> a[i];
    for( int i = 0 ; i < n ; i++ ) cin >> b[i];
    for( int i = 0 ; i < n ; i++ ) cin >> c[i];
    sort( a , a + n );
    sort( b , b + n );
    sort( c , c + n );
    ll x = 0;
    int d = 0 , e = 0;
    
    for( int i = 0 ; i < n ; i++ ) {
        d = 0; e = 0;
        for( int j = n - 1 ; j >= 0 ; j-- ) {
            if( a[j] < b[i] ) {
                d = j + 1;
                break;
            }
        }
        for( int j = 0 ; j < n ; j++ ) {
            if( b[i] < c[j] ) {
                e = n - j;
                break;
            }
        }
        x += d * e;
    }
    cout << x;
}


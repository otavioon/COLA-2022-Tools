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
    for( int i = 0 ; i < n ; i++ ) {
        for( int j = 0 ; j < n ; j++ ) {
            if( b[j] > a[i] ) {
                for( int k = 0 ; k < n ; k++ ) {
                    if( c[k] > b[j] ) {
                        x++;
                    } else break;
                }
            } else break;
        }
    }
    cout << x;
}

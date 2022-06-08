#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 1e5 + 10 ;

int arr[N] , brr[N] , crr[N] , n ;

int gr( int x ) {
    int lo = 1 , hi = n , mid , ans = -1 ;
    while( lo <= hi ) {
        mid = ( lo + hi ) / 2 ;
        if( crr[mid] > x ) {
            ans = mid ;
            hi = mid - 1 ;
        } else {
            lo = mid + 1 ;
        }
    }
    return ( ans == -1 ) ? 0 : n - ans + 1 ;
}

int ls( int x ) {
    int lo = 1 , hi = n , mid , ans = -1 ;
    while( lo <= hi ) {
        mid = ( lo + hi ) / 2 ;
        if( arr[mid] < x ) {
            ans = mid ;
            lo = mid + 1 ;
        }
        else {
            hi = mid - 1 ;
        }
    }
    return ( ans == -1 ) ? 0 : ans ;
}

long long solve( ) {
    sort( arr+1 , arr+1+n ) ;
    sort( brr+1 , brr+1+n ) ;
    sort( crr+1 , crr+1+n ) ;
    long long ans = 0 ;
    for( int i = 1 ; i <= n ; i++ ) {
        ans += ls( brr[i] ) * gr( brr[i] ) ;
    }
    return ans ;
}

int main() {
    scanf("%d" , &n ) ;
    for( int i = 1 ; i <= n ; i++ ) scanf("%d" , &arr[i] ) ;
    for( int i = 1 ; i <= n ; i++ ) scanf("%d" , &brr[i] ) ;
    for( int i = 1 ; i <= n ; i++ ) scanf("%d" , &crr[i] ) ;
    long long ans = solve() ;
    printf("%lld\n" , ans ) ;
    return 0 ;
}

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MAX_INF 0x7f
#define MAX_INF_VAL 0x7f7f7f7f
#define pi 3.141592653589
#define eps 1e-10
//#define p 2173412051LL
#define sz 2
 
using namespace std;

ll a[ 1001 ];
ll sum[ 2020 ];

int main() {
	int n, x;
	ll ans = 0;
	scanf( "%d", &n );
	for( int i = 1; i <= n; ++i ) {
		scanf( "%d", &x );
		++a[ x ];
	}
	for( int i = 1; i <= 1000; ++i )
		sum[ i ] = sum[ i - 1 ] + a[ i ];
	for( int i = 1; i <= 1000; ++i ) {
		if( !a[ i ] )
			continue;
		for( int j = 1; j < i; ++j ) {
			if( !a[ j ] )
				continue;
			if( j - 1 > i - j )
				ans += sum[ j - 1 ] - sum[ i - j ];
			if( j + j > i )
				ans += a[ j ] * ( a[ j ] - 1 ) / 2;
		}
		ans += a[ i ] * ( a[ i ] - 1 ) / 2 * sum[ i - 1 ];
		if( a[ i ] >= 3 )
			ans += a[ i ] * ( a[ i ] - 1 ) * ( a[ i ] - 2 ) / 6;
	}
	printf( "%lld", ans );
	return 0;	
}
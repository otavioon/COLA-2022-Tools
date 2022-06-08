#include <cstdio>
#include <cstring>
#define MAXN 105
char s[MAXN];
int k, sum;
int main() {
	scanf ( "%s %d", s, &k );
	int len = strlen ( s );
	if ( len == 1 )
		return ! printf ( "%d", k >> 1 );
	int cnt1 = 1, cnt2 = 1;
	for ( int i = 1;i < len;i ++ )
		if ( s[i] == s[i - 1] )
			cnt1 ++;
		else
			break;
	for ( int i = len - 1;i >= 0;i -- )
		if ( s[i] == s[i + 1] )
			cnt2 ++;
		else
			break; 
	for ( int i = 1;i < len;i ++ )
		if ( s[i] == s[i - 1] ) {
			sum ++;
			s[i] = '1';
		}
	if ( s[0] == s[len - 1] ) {
		if ( cnt1 == cnt2 && cnt1 == len )
			printf ( "%lld", ( 1ll * len * k ) >> 1 );
		else if ( ( cnt1 + cnt2 ) % 2 )
				printf ( "%lld", 1ll * sum * k - ( k - 1 ) );
		else
			printf ( "%lld", 1ll * sum * k );
	}
	else
		printf ( "%lld", 1ll * sum * k );
	return 0;
}
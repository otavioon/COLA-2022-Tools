#include <cstdio>
#include <cstring>

#define Int register int

char str[105] = {};
int k, l;
long long Ans;

inline void Work () {
	scanf ( "%s %d", str + 1, &k ), l = strlen ( str + 1 );
	for ( Int i = 1, r; i <= l; ) {
		r = i;
		while ( r < l && str[r + 1] == str[r] && ++ r );
		if ( r ^ i ) Ans += ( ( r - i + 1 ) >> 1 );
		i = r + 1;
	}
	if ( str[1] == str[l] ) {
		if ( str[l - 1] == str[l] ) Ans += k - 1, str[l] = '%';
		else Ans += k - 1, str[1] = '%';
	}
	for ( Int i = 1, r; i <= l; ) {
		r = i;
		while ( r < l && str[r + 1] == str[r] && ++ r );
		if ( r ^ i ) Ans += ( 1LL * ( r - i + 1 ) >> 1 ) * ( k - 1 );
		i = r + 1;
	}
	printf ( "%lld\n", Ans );
}

int main () {
	Work ();
	return 0;
}
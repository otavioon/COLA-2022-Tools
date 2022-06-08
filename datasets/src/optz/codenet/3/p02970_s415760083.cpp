#include <bits/stdc++.h>
//#include<unordered_map>
#define debug(x) (cout << "#x = " << (x) << endl)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
//#define mid (l + r >> 1)
#define lowbit(x) (x & -x)
#define Set(x, i) memset(x, i, sizeof x)
#define R register
#define For( i, j, k ) for(R int i = (j); i <= (k); ++i)
#define foR( i, j, k ) for(R int i = (j); i >= (k); --i)
#define Cross( i, j, k ) for(R int i = (j); i; i = (k))using namespace std;
typedef long long ll;
using namespace std;
const ll N = 100011;
const ll Inf = 0x3f3f3f3f3f3f;

namespace IO {

	#define dd ch = getchar()
	inline ll read() {
		ll x = 0; bool f = 0; char dd;
		for (; !isdigit (ch); dd) f ^= (ch == '-');
		for (; isdigit (ch); dd)  x = x * 10 + (ch ^ 48);
		return f? -x: x;
	}
	#undef dd

	inline void write ( ll x ) {
		if (x < 0) putchar ('-'), x = -x;
		if (x > 9) write (x / 10); putchar ( x % 10 | 48 );
	}

	inline void wrn ( ll x ) { write(x); putchar (' '); }

	inline void wln ( ll x ) { write(x); putchar ('\n'); }

	inline void wlnn ( ll x, ll y ) { wrn(x); wln (y); }

}

using namespace IO;

namespace Cesare {
	
	ll n, D, cc = 0, A[N];
	
	int main() {
		n = read(), D = read();
		for (R int i = D + 1; i <= n; i += 2 * D + 1) A[++cc] = i;
		if (A[cc] + D < n) ++cc;
		wln(cc);
		return 0;
	}
	
}

int main()
{
	return Cesare::main();
}

/*

*/


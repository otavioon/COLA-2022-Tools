#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

int n;
int m;
int x[3][3];

int main () {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf ("%d", &x[i][j]);
	for (int i = 1; i < 3; i++)
		for (int j = 1; j < 3; j++)
			if (x[i][j] != x[i][0] + x[0][j] - x[0][0]) {
				printf ("No\n");
				re 0;
			}
	printf ("Yes\n");
	return 0;
}
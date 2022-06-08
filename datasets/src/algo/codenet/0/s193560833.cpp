#include<bits/stdc++.h>
typedef long long ll;
inline ll read() {ll x = 0;char ch = getchar(), w = 1;while(ch < '0' || ch > '9') {
if(ch == '-') w = -1;ch = getchar();}while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();
}return x * w;}
void write(ll x) {if(x < 0) putchar('-'), x = -x;if(x > 9) write(x / 10);putchar(x % 10 + '0');}
inline void writeln(ll x) {write(x);puts("");}
using namespace std;
const int N = 310;
char s[N];
int n;
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	ll m = read();
	ll ans = 0;
	if(m == 2) {
		for(int i = 1; i <= n; ++i) s[i + n] = s[i];
		n *= 2;
	}
	for(int i = 1, j; i <= n; i = j) {
		j = i;
		while(s[i] == s[j]) ++j;
		ans += (j - i) / 2;
	}
	if(m == 1 || m == 2) {
		writeln(ans);
		return 0;
	}
	ll cnt = ans;
	ans *= 2;
	if(s[n] == s[1]) {
		if(s[n] != s[n - 1])
			ans += m - 1;	
	}
	ans += cnt * (m - 2);
//	printf("ans=%lld\n", ans);
	/*
	axaaxaaaa
	*/
	writeln(ans);
	
	return 0;
}

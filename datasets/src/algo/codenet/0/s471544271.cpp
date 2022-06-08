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
	for(int i = 1, j; i <= n; i = j) {
		j = i;
		while(s[i] == s[j]) ++j;
		ans += (j - i) / 2;
	}
	if(s[1] != s[n]) {
		writeln(m * ans);
		return 0;
	}
	int l = 1, r = n;
	while(s[l] == s[1]) ++l;
	while(s[r] == s[1]) --r;
	if(r == 0) {
		writeln(n * m / 2);
		return 0;
	}
/*	ans = 0;
	for(int i = l, j; i <= r; i= j) {
		j = i;
		while(s[i] == s[j]) ++j;
		ans += (j - i) / 2;
	}*/
//	printf("l=%d,r=%d,ans=%d ()%d %d %d\n", l, r,ans,(l-1)/2,(n-r)/2,(l-1+n-r)/2);
	writeln(ans * m - ((l - 1) / 2 + (n - r) / 2 - (l - 1 + n - r) / 2) * (m - 1));
//	printf("ans=%lld\n", ans);
	/*
	axaaxaaaa
	*/
	
	return 0;
}

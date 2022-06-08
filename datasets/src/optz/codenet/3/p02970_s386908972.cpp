#include <cstdio>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
using namespace std;
template <typename lx> inline void read(lx &x){
	x = 0;int f = 1;char c = getchar();
	for(;c < '0' || '9' < c; c = getchar()) if(c == '-') f = -1;
	for(;'0' <= c && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;return;
}
template <typename lx> inline void print(lx x){
	if(x < 0) putchar('-'),x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
	return;
}
#define rg register
#define ll long long
#define r_2(a,b) read(a),read(b)
#define r_3(a,b,c) read(a),read(b),read(c)
#define print_n(a) print(a),puts("")
#define print_(a) print(a),putchar(' ')
const int inf = 2147483647;
int n,d;
int main()
{
	r_2(n,d);
	d = d * 2 + 1;
	print_n((n + d - 1) / d);
	return 0;
}
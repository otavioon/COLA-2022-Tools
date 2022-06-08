#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define LL long long
#define int LL
const LL inf=0x3f3f3f3f;
using namespace std;
template<typename tp> inline void read(tp &x)
{
	x=0; char c=getchar(); bool f=0;
	for(;c<'0'||c>'9';f|=(c=='-'),c = getchar());
	for(;c>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0',c = getchar());
	if(f) x=-x;
}
int n,m;
signed main()
{
	read(n),read(m);
	printf("%lld\n",n*m-n-m+1);
	return 0;
}
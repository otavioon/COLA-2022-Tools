#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<stack>
#include<queue>
#include<map>
#define size 300010
#define ll long long
#define db double
#define il inline
#define rint register int
#define gc getchar()
#define rep(i,s,n) for (register int i=s;i<=n;i++)
#define sro_zyb_orz int main()

using namespace std;

il ll r()
{
	char c; ll x,f=1;
	for (c=gc;!isdigit(c);c=gc) if (c=='-') f=-1; x=c-'0';
	for (c=gc;isdigit(c);c=gc) x=x*10+c-'0'; return x*f;
}

int c[5][5];


sro_zyb_orz
{
	rep(i,1,3) rep(j,1,3) c[i][j]=r();
	if (c[1][1]+c[2][2]+c[3][3]==c[1][3]+c[2][2]+c[3][1]
	&&c[1][3]+c[2][2]+c[3][1]==c[1][2]+c[2][3]+c[3][1]) 
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}


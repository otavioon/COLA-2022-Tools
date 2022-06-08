/*************************************************
 *************************************************
 *************************************************
 *** _________________  |            |  |     /***
 ***         |          |            |  |    / ***
 ***         |          |            |  |   /  ***
 ***         |          |            |  |  /   ***
 ***         |          |            |  | /    ***
 ***         |          |____________|  |/  en ***
 ***         |          |            |  |\     ***
 ***         |          |            |  | \    ***
 *** _____   |          |            |  |  \   ***
 ***   |     |          |            |  |   \  ***
 ***   \     /          |            |  |    \ ***
 ***    \___/           |            |  |     \***
 *************************************************
 *************Written by: JiangHaoKai*************
 *************************************************/

#pragma GCC optimize(2)
#pragma G++ optimize(2)
#pragma comment(linker,"/STACK:102400000,102400000")

//#include <bits/stdc++.h>
#include <map>
#include <set>
#include <list>
#include <array>
#include <cfenv>
#include <cmath>
#include <ctime>
#include <deque>
#include <mutex>
#include <queue>
#include <ratio>
#include <regex>
#include <stack>
#include <tuple>
#include <atomic>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <chrono>
#include <cstdio>
#include <cwchar>
#include <future>
#include <limits>
#include <locale>
#include <memory>
#include <random>
#include <string>
#include <thread>
#include <vector>
#include <cassert>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <cwctype>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <ccomplex>
#include <cstdbool>
#include <iostream>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <cinttypes>
#include <cstdalign>
#include <stdexcept>
#include <typeindex>
#include <functional>
#include <forward_list>
#include <system_error>
#include <unordered_map>
#include <unordered_set>
#include <scoped_allocator>
#include <condition_variable>
//#include <conio.h>
//#include <windows.h>
using namespace std;

typedef long long LL;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef float fl;
typedef double ld;
typedef pair<int,int> pii;
#define ui(n) ((unsigned int)(n))
#define LL(n) ((long long)(n))
#define ull(n) ((unsigned long long)(n))
#define fl(n) ((float)(n))
#define ld(n) ((double)(n))
#define char(n) ((char)(n))
#define Bool(n) ((bool)(n))
#define fixpoint(n) fixed<<setprecision(n)
const int INF=1061109567;
const LL LINF=4557430888798830399;
#define PI 3.1415926535897932384626433832795028841971
#define MP make_pair
#define MT make_tuple
#define All(a) (a).begin(),(a).end()
#define pall(a) (a).rbegin(),(a).rend()
#define MOD 1000000007
#define sz(a) ((int)(a).size())
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repa(i,a,n) for(int i=a;i<n;i++)
#define repa1(i,a,n) for(int i=a;i<=n;i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define repd1(i,n) for(int i=n;i>=1;i--)
#define repda(i,n,a) for(int i=n;i>a;i--)
#define repda1(i,n,a) for(int i=n;i>=a;i--)
#define FOR(i,a,n,step) for(int i=a;i<n;i+=step)
#define repv(itr,v) for(__typeof((v).begin()) itr=(v).begin();itr!=(v).end();itr++)
#define repV(i,v) for(auto i:v)
#define repE(i,v) for(auto &i:v)
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x) MS(x,0)
#define MCP(x,y) memcpy(x,y,sizeof(y))
#define sqr(x) ((x)*(x))
#define UN(v) sort(All(v)),v.erase(unique(All(v)),v.end())
#define filein(x) freopen(x,"r",stdin)
#define fileout(x) freopen(x,"w",stdout)
#define fileio(x)\
	freopen(x".in","r",stdin);\
	freopen(x".out","w",stdout)
#define filein2(filename,name) ifstream name(filename,ios::in)
#define fileout2(filename,name) ofstream name(filename,ios::out)
#define file(filename,name) fstream name(filename,ios::in|ios::out)
#define Pause system("pause")
#define Cls system("cls")
#define fs first
#define sc second
#define PC(x) putchar(x)
#define GC(x) x=getchar()
#define Endl PC('\n')
#define SF scanf
#define PF printf

inline int Read()
{
    int X=0,w=0;char ch=0;while(!isdigit(ch)){w|=ch=='-';ch=getchar();}while(isdigit(ch))X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w?-X:X;
}
inline void Write(int x){if(x<0)putchar('-'),x=-x;if(x>9)Write(x/10);putchar(x%10+'0');}

inline LL powmod(LL a,LL b){LL res=1;a%=MOD;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
inline LL gcdll(LL a,LL b){return b?gcdll(b,a%b):a;}
const int dx[]={0,1,0,-1,1,-1,-1,1};
const int dy[]={1,0,-1,0,-1,-1,1,1};
/**************************************************************Begin***************************************************************/
const int maxn=100010;

int n,ans;
multiset<int> s;

int main()
{
	SF("%d",&n);
	rep(i,n)
	{
		int x;SF("%d",&x);
		s.insert(x);
	}
	
	for(multiset<int>::iterator i=(--s.end());;)
	{
		bool f=0;
		for(multiset<int>::iterator j=(--s.end());;j--)
		{
			if(i!=j&&pow(2,log2(*i+*j))==*i+*j)
			{
				s.erase(i);
				s.erase(j);
				f=1;
				ans++;
				break;
			}
			if(j==s.begin()) break;
		}
		
		if(i==s.begin()) break;
		if(!f) i--; else i++;
	}
	
	PF("%d",ans);

	return 0;
}
/***************************************************************End****************************************************************/

#define _USE_MATH_DEFINES
#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<iostream>
#include<unordered_set>

using namespace std;

#define dprint(Exp,...) if(Exp){fprintf(stderr, __VA_ARGS__);}
#define printe(...) fprintf(stderr, __VA_ARGS__);
#define PrtExp(_Exp)  cerr<< #_Exp <<" = "<< (_Exp)
#define PrtExpN(_Exp)  cerr<< #_Exp <<" = "<< (_Exp) <<"\n"

#define SINT(n) scanf("%d",&n)
#define SINT2(n,m) scanf("%d %d",&n,&m)
#define SINT3(n,m,o) scanf("%d %d %d",&n,&m,&o)
#define SINT4(n,m,o,P) scanf("%d %d %d %d",&n,&m,&o,&P)
#define SINT5(n,m,o,P,q) scanf("%d %d %d %d %d",&n,&m,&o,&P,&q)
#define SLL(n) scanf("%lld",&n)
#define SLL2(n,m) scanf("%lld %lld",&n,&m)
#define SLL3(n,m,o) scanf("%lld %lld %lld",&n,&m,&o)
#define SST(s) scanf("%s",s)
#define SCH(c) scanf("%c",&c)

#define GC() getchar()

#define PINT(n) printf("%d",(int)(n))
#define PINT2(n,m) printf("%d %d",(int)(n),(int)(m))
#define PINT3(n,m,l) printf("%d %d %d",(int)(n),(int)(m),(int)(l))
#define PLL(n) printf("%lld",(long long)(n))
#define PST(s) printf("%s",(s))
#define PCH(s) printf("%c",(s))

#define PINTN(n) printf("%d\n",(int)(n))
#define PINT2N(n,m) printf("%d %d\n",(int)(n),(int)(m))
#define PINT3N(n,m,l) printf("%d %d %d\n",(int)(n),(int)(m),(int)(l))
#define PLLN(n) printf("%lld\n",(long long)(n))
#define PSTN(s) printf("%s\n",(s))
#define PCHN(s) printf("%c\n",(s))

#define PSP() printf(" ")
#define PN() printf("\n")

#define PC(c) putchar(c)
#define CSP (' ')
#define SN ("\n")

#define rep(i,a) for(int i=0;i<a;i++)
#define reP(i,a) for(int i=0;i<=a;i++)
#define Rep(i,a) for(int i=a-1;i>=0;i--)
#define ReP(i,a) for(int i=a;i>=0;i--)

#define rEp(i,a) for(i=0;i<a;i++)
#define rEP(i,a) for(i=0;i<=a;i++)
#define REp(i,a) for(i=a-1;i>=0;i--)
#define REP(i,a) for(i=a;i>=0;i--)

#define repft(i,a,b) for(int i=a;i<b;i++)
#define repfT(i,a,b) for(int i=a;i<=b;i++)
#define Repft(i,a,b) for(int i=a-1;i>=b;i--)
#define RepfT(i,a,b) for(int i=a;i>=b;i--)

#define foreach(a,it) for(auto it = a.begin(); it != a.end(); ++it)

#define FILL(a,v) fill(begin(a),end(a), v)
#define FILL0(a) memset(a,0,sizeof(a))
#define FILL1(a) memset(a,-1,sizeof(a))

typedef long long ll;

typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll>   Pll;


const int INF = 1'010'000'000; // 0x3C33'6080
const ll INFLL = 0x1f1f1f1f1f1f1f1fLL;//2,242,545,357,980,376,863

template <class A, class B> inline ostream& operator<<(ostream& st, const pair<A, B>& P) { return st << "(" << P.first << "," << P.second << ")"; };
template <class A, class B> inline pair<A, B> operator+(const pair<A, B>& P, const pair<A, B>& Q) { return pair<A, B>(P.first + Q.first, P.second + Q.second); };
template <class A, class B> inline pair<A, B> operator-(const pair<A, B>& P, const pair<A, B>& Q) { return pair<A, B>(P.first - Q.first, P.second - Q.second); };

#define fs  first
#define sc  second

int bitCount(unsigned int bits) {
	bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);    //  2bitごとに計算
	bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);    //  4bitごとに計算
	bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);    //  8bitごとに計算
	bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);    //  16ビットごとに計算   
	return (bits & 0x0000ffff) + (bits >> 16);    //  32ビット分を計算   
}

template<typename T>
using heap = priority_queue<T, vector<T>, greater<T>>;



int count32bit(unsigned v) {
	unsigned count = (v & 0x55555555) + ((v >> 1) & 0x55555555);
	count = (count & 0x33333333) + ((count >> 2) & 0x33333333);
	count = (count & 0x0f0f0f0f) + ((count >> 4) & 0x0f0f0f0f);
	count = (count & 0x00ff00ff) + ((count >> 8) & 0x00ff00ff);
	return (count & 0x0000ffff) + ((count >> 16) & 0x0000ffff);
}

int MSB32bit(unsigned v) {
	if (v == 0) return false;
	v |= (v >> 1);
	v |= (v >> 2);
	v |= (v >> 4);
	v |= (v >> 8);
	v |= (v >> 16);
	return count32bit(v) - 1;
}


int main() {
	int ret = 0;
	int n;
	cin >> n;

	multiset<int> m;

	rep(i, n) {
		int a;
		cin >> a;
		m.insert(a);
	}
	while (m.size() > 1) {
		auto back = --m.end();
		int t = *back;
		m.erase(back);

		int msb = MSB32bit(t);
		unsigned p2 = 2u << msb;
		int sub = p2 - t;


		auto it = m.find(sub);
		if (it != m.end()) {
			//cout << t << " " << sub << endl;

			ret++;
			m.erase(it);
		}
	}
	cout << ret << endl;


}
#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

int na;
int a[MAXN];

int b[MAXN],nb;
int c[MAXN],nc;
int d[MAXN],nd;

int solve() {
	nb=0; REP(i,na) b[nb++]=a[i];
	sort(b,b+nb);
	int ret=0;
	while(nb>0) {
		int largest=b[nb-1];
		int target=1; while(target<=largest) target*=2;
		nc=0; int nhalf=0; while(nb>0&&b[nb-1]>=target/2) { int cur=b[--nb]; if(cur==target/2) ++nhalf; else c[nc++]=cur; }
		ret+=nhalf/2;
		nd=0; REP(i,nb) d[nd++]=b[i];
		nb=0;
		//printf("target=%d (nhalf=%d)\n",target,nhalf);
		//printf("c:"); REP(i,nc) printf(" %d",c[i]); puts("");
		//printf("d:"); REP(i,nd) printf(" %d",d[i]); puts("");
		int ci=0,di=0;
		while(ci<nc&&di<nd) {
			int have=c[ci]+d[di];
			if(have<target) b[nb++]=d[di++]; else if(have>target) ++ci; else { ++ret; ++ci; ++di; }
		}
		while(di<nd) b[nb++]=d[di++];
	}
	return ret;
}

void run() {
	scanf("%d",&na);
	REP(i,na) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}

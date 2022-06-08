//natsugiri
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
 
typedef long long LL;
typedef vector<int> VI;
 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
 
int N;
pair<LL, int> A[200111];
 
void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", &A[i].first);
    sort(A, A+N);
 
    int ans = 0;
    for (int i=N; i--;) {
	if (A[i].second) continue;
	LL t = 2LL<<__lg(A[i].first);
	int k = lower_bound(A, A+i, make_pair(t - A[i].first, 0)) - A;
	if (0 < k && k <= i && A[i].first + A[k-1].first == t) {
	    ans++;
	    A[k-1].second = 1;
	}
    }
    printf("%d\n", ans);
}
 
int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}
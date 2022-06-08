#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int A[N], B[N], C[N];
long long D[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &A[i]);
	for(int i=0; i<n; i++) scanf("%d", &B[i]);
	for(int i=0; i<n; i++) scanf("%d", &C[i]);
	sort(A, A+n);
	sort(B, B+n);
	sort(C, C+n);
	int j=0;
	for(int i=0; i<n; i++) {
		while(j<n && B[i]>=C[j]) j++;
		D[i]+=n-j;
	}
	for(int i=n-2; i>=0; i--) D[i]+=D[i+1];
	// for(int i=0; i<n; i++) printf("%d ", D[i]); puts("");
	j=0;
	long long ans=0;
	for(int i=0; i<n; i++) {
		while(j<n && A[i]>=B[j]) j++;
		ans+=D[j];
	}
	printf("%lld\n", ans);
	return 0;
}
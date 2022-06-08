#include<stdio.h>
#include<algorithm>
#include<functional>
#include<cmath>
using namespace std;
long long A[100010], B[100010], C[100010];		
long long p[100010] = { 0 };
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%lld", &B[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%lld", &C[i]);
	}
	sort(A, A + N);
	sort(B, B + N);
	sort(C, C + N);
	int j = 0, l = 0;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		while (B[i] >= C[j]) {
			if (j == N) break;
			j++;
		}
		p[i] = N - j;
		sum += p[i];
	}
	long long an = 0;
	for (int i = 0; i < N; i++) {
		while (A[i] >= B[l]) {
			if (l == N) break;
			sum -= p[l];
			l++;
		}
		an += sum;
	}
	printf("%lld", an);
	return 0;
}
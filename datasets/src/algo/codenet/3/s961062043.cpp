#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	long *A = new long[N];
	long *B = new long[N];
	long *C = new long[N];

	for (int i = 0; i < N; i++)
		scanf("%ld", &A[i]);
	for (int i = 0; i < N; i++)
		scanf("%ld", &B[i]);
	for (int i = 0; i < N; i++)
		scanf("%ld", &C[i]);
	sort(&A[0], &A[N]);
	sort(&B[0], &B[N]);
	sort(&C[0], &C[N]);

	long sum = 0;

	for (long i = 0; i < N; i++) {
		for (long j = 0; j < N; j++) {
			if (A[i] < B[j]) {
				for (long k = 0; k < N; k++) {
					if (B[j] < C[k]) {
						sum += (N - j) * (N - k);
						break;
					}
				}
				break;
			} 
		}
	}

	printf("%ld\n", sum);

	delete[] A;
	delete[] B;
	delete[] C;
}

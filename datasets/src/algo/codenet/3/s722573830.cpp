#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int *A = new int[N];
	int *B = new int[N];
	int *C = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &B[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &C[i]);
	sort(&A[0], &A[N]);
	sort(&B[0], &B[N]);
	sort(&C[0], &C[N]);

	long sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i] < B[j]) {
				for (int k = 0; k < N; k++) {
					if (B[j] < C[k]) {
						sum += N - k;
						break;
					}
				}
			} 
		}
	}

	printf("%ld\n", sum);

	delete[] A;
	delete[] B;
	delete[] C;
}

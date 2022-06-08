#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <list>
using std::list;

int main() {
	int N;
	scanf("%d", &N);

	int* A = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int ans = 0;
	//list<int>** AKouho = new list<int>*[N];
	//for (int i = 0; i < N; i++) {
	//	AKouho[i] = NULL;
	//}

	// 調査対象
	for (int i = 0; i < N; i++) {
		// 相手
		for (int j = 0; j < N; j++) {
			if (i != j) {
				// 調査するべき数
				int n = A[i] + A[j];
				if ((n & (n - 1)) == 0) {
					//if (AKouho[i] == NULL) AKouho[i] = new list<int>;
					//AKouho[i]->push_back(A[j]);
					ans++;
				}
			}
		}
	}

	//int max = 0;
	//for (int i = 0; i < N; i++) {
	//	if (AKouho[i] == NULL) continue;
	//	int size = AKouho[i]->size();
	//	if (size > max) max = size;
	//}

	//int ans = 0;
	//for (int i = 0; i < N; i++) {
	//	if (AKouho[i] == NULL) continue;
	//	int size = AKouho[i]->size();
	//	if (size > 0) ans++;
	//}
	printf("%d\n", ans / 2);

	return 0;
}

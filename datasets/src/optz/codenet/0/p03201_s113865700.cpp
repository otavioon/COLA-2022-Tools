// 解説閲覧済
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <list>
#include <forward_list>
using namespace std;

int main() {
	int N, dummy;
	dummy = scanf("%d", &N);

	forward_list<int> A;
	int tmp;
	for (int i = 0; i < N; i++) {
		dummy = scanf("%d", &tmp);
		A.push_front(tmp);
	}

	A.sort(std::greater<int>());

	int ans = 0;
	forward_list<int>::iterator itr;
	forward_list<int>::iterator bitr;
	int n;

	// 調査対象
	while (!A.empty()) {
		int target = A.front();
		A.pop_front();

		if (A.empty()) break;

		itr = A.begin();
		while (itr != A.end()) {
			// 調査するべき数
			n = target + *itr;
			if ((n & (n - 1)) == 0) {
				ans++;
				if (itr == A.begin()) A.pop_front();
				else A.erase_after(bitr);
				break;
			}
			bitr = itr;
			++itr;
		}
	}

	printf("%d\n", ans);

	return 0;
}

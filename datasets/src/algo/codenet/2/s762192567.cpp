#include <iostream>
#include <set>
#include <functional>

using namespace std;

int main()
{
	int N;
	cin >> N;
	multiset<int, greater<>> A;

	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		A.insert(x);
	}

	int ans = 0;
	while (!A.empty()) {
		int x = *A.begin();
		int s = 1;
		while (s <= x) {
			s *= 2;
		}
		A.erase(A.begin());
		auto it = A.find(s - x);
		if (it != A.end()) {
			A.erase(it);
			++ans;
		}
	}
	cout << ans << endl;
}

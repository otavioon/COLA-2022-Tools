#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		A.push_back(x);
	}
	sort(A.begin(), A.end());
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

	int maxcand = A[N - 1] + A[N - 2];
	int maxt = log2(maxcand);

	map<int, int> m;

	for (int i = 0; i < N; i++) {
		if (m.count(A[i]) > 0) {
			m[A[i]]++;
		}
		else {
			m[A[i]] = 1;
		}
	}

	int counterPair = 0;
	while (m.size() > 0) {
		auto p = m.end(); p--;
		pair<int,int> pr = *p;
		int x = pr.first;

		bool found = false;
		for (int i = 0; i < maxt; i++) {
			int z = pow(2, maxt - i);
			int y = z - x;
			if (y <= 0) continue;
			auto q = m.find(y);
			if (q != m.end()) {
				if (y == x && m[y] == 1) continue;
				m[x]--; if (m[x] <= 0) m.erase(x);
				m[y]--; if (m[y] <= 0) m.erase(y);
				found = true;
				counterPair++;
				break;
			}
		}
		if (!found) {
			m[x]--; if (m[x] <= 0) m.erase(x);
		}


	}


	//while (s.size()>0) {
	//	auto p = s.end(); p--;
	//	int x = *p;

	//	bool found = false;		
	//	for (int i = 0; i < maxt; i++) {
	//		int z = pow(2, maxt - i);
	//		int y = z - x;
	//		if (y <= 0) continue;			
	//		auto q = s.find(y);
	//		if (q != s.end()) {
	//			if (y == x && s.count(y) == 1) continue;
	//			s.erase(p); s.erase(q);
	//			found = true;
	//			counterPair++;
	//			break;
	//		}
	//	}
	//	if (!found) {
	//		s.erase(x);			
	//	}
	//}
	cout << counterPair << endl;
	return 0;
}
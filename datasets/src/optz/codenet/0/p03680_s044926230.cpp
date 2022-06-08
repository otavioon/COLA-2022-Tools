#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iterator>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))


int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector<int> ever(0);

	ever.push_back(0);
	int num = 0, count = 0;
	while (find(ever.begin(), ever.end(), a[num]) == ever.end() && count <= N + 1) {
		if (a[num] == 1) {
			cout << ever.size();
			return 0;
		}
		else {
			ever.push_back(a[num]);
			num = a[num];
			count++;
		}
	}
	cout << -1;
	return 0;
}
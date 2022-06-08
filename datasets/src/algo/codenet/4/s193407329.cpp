#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <map>
#include <list>
#include <climits>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>

// #define cerr if(false)cerr
#define watch(x) cerr << "> " << #x << ": " << x << "\n";

using namespace std;

template <typename T>
std::ostream &operator <<(std::ostream &out, vector<T> &v) {
	for (typename vector<T>::size_type i = 0; i < v.size(); ++i)
		out << v[i] << " ";
	out << "\n";
    return out;
}
template <typename T, typename N>
std::ostream &operator <<(std::ostream &out, vector<pair<T, N> > &v) {
	for (size_t i = 0; i < v.size(); ++i)
		out << "(" << v[i].first << ", " << v[i].second << ") ";
	out << "\n";
    return out;
}
template <typename T>
std::ostream &operator <<(std::ostream &out, vector<vector<T> > &v) {
	for (size_t i = 0; i < v.size(); ++i) {
		for (size_t j = 0; j < v[i].size(); ++j) {
			out << v[i][j] << " ";
		}
		out << "\n";
	}
   	return out;
}

bool dislike(int n, set<int> &dig) {
	while (n) {
		if (dig.find(n % 10) != dig.end()) {
			return true;
		}

		n /= 10;
	}

	return false;
}

int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	set<int> disliked;
	int d;
	for (int i = 0; i < k; ++i) {
		cin >> d;
		disliked.insert(d);
	}

	for (int i = n; i <= 100000; ++i) {
		if (!dislike(i, disliked)) {
			cout << i << "\n";
			return 0;
		}
	}

	return 0;

}
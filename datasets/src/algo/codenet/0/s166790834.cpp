#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cmath>

using namespace std;

int main() {

	string str, s;
	long long a, b, r, count = 0, flag = 0,f=0;
	cin >> str >> a;

	r = str.size();

	str = str + str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == str[i + 1]) {
			count++;
			i++;
		}
	}

	b = count;

	if (count % 2 == 1) {
		flag = 1;
		count++;
	}

	count = count / 2;

	if (a % 2 == 1) {
		f = 1;
	}

	if (r == 1) {
		cout << a / 2 << endl;
	}
	else if (flag == 0 && f == 0) {
		cout << count * a << endl;
	}
	else if (flag == 1 && f == 0) {
		cout << b * a / 2 << endl;
	}
	else if (flag == 0 && f == 1) {
		cout << count * a << endl;
	}
	else if (flag == 1 && f == 1) {
		cout << b * (a - 1) / 2 + count - 1 << endl;
	}

	

	return 0;
}

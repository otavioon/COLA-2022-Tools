#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
		int N, K;
		cin >> N >> K;
		set<int> st;
		for (int i = 0; i < K; i++) {
				int t;
				cin >> t;
				st.insert(t);
		}

		bool flg = true;
		for (int i = 1; i < 100000; i++) {
				string S = to_string(i);
				if (i >= N) {
						int t = i;
						for (int j = 0; j < S.size(); j++) {
								if (st.find(t%10) != st.end()) {
										flg = false;
										break;
								} else {
										t /= 10;
								}
						}

						if (!flg) {
								flg = true;
						} else {
								cout << i << endl;
								return 0;
						}
				}
		}
		return 0;
}

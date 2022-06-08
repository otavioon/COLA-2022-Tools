#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// INT VS LL

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // string s;
    int n, k;
    cin >> n >> k;
    vector<bool> bad(10);
    for (int i = 0; i < k; ++i) {
    	int foo;
    	cin >> foo;
    	bad[foo] = true;
    }

    for (int i = n; true; ++i) {
    	string s = to_string(i);
    	bool good = true;
    	for (auto c: s) {
    		good &= !bad[c - '0'];
    	}
    	if (good) {
    		cout << i << endl;
    		return 0;
    	}

    }
    assert(false);
    return 0;

    // int len = s.size();
    // int ten_pw = 1;
    // for (int i = 0; i < len - 1; ++i) ten_pw *= 10;
    // for (int i = 0; i < (int) s.size(); ++i) {
    // 	int cur = (s[i] - '0');
    // 	if (bad(cur)) {
    // 		if (cur == 9) {

    // 		}
    // 		else {
    // 			for (int d = 0; d < 10; ++d) {
    // 				if (bad[d]) continue;
    // 				// should I change to D
    // 				if (!bad[d]) {
    // 					ans += (d * ten_pw * (len - i));
    // 					break;
    // 				}
    // 			}
    // 			int x 
    // 		}
    // 	}
    // 	ten_pw /= 10;
    // }

    return 0;
}

/*
8382 
i = 0
ans += 2000
d * 1000
*/
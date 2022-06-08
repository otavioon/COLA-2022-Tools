#include <iostream>
#include <vector>
#include <iomanip>
#include <stack>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <time.h>
#include <complex>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=n;i>0;i--)
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define SORT(v) sort((v).begin(),(v).end())
const ll INF = (1LL << 50);
typedef pair<int, int> P;

int main() {

	string s;
	cin >> s;

	int k;
	cin >> k;

	int l = s.size();

	int flag = 0;
	for (int i = 1; i < l; i++) {
		if (s[i] != s[i - 1]) {
			flag = 1;
		}
	}



	int flag2 = 0;
	int cnt2 = 0;
	if (flag == 0 && l%2==1) {//奇数
		int a = (l * k) / 2;
		cout << a << endl;
	}
	else {
		if(l==1)cout << k / 2 << endl;
		else {
			ll cnt = 0;
			for (int i = 1; i < l;) {
				if (s[i] == s[i - 1]) {
					cnt++;
					i += 2;
				}
				else {
					i++;
				}
			}

			if (s[0] == s[l - 1] && s[l - 1] != s[l - 2]) {
				cnt2++;
				flag2 = 1;
			}

			if (flag2 == 1) {
				if(k==1)cout << cnt << endl;
				else cout << (ll)cnt * k + k - 1 << endl;
			}
			else cout << (ll)cnt * k << endl;
		}
	}

	return 0;

}
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define i64 int64_t
#define ff(ii,nn,mm) for(int ii=nn;ii<mm;ii++)
#define st(vvv) sort(vvv.begin(),vvv.end())
#define rvs(vvv) reverse(vvv.begin(),vvv.end())
int inf = 1000000007;

using namespace std;

int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	set<int> abd;
	ff(i, 0, k) {
		int a;
		cin >> a;
		abd.insert(a);
	}
	i64 ans = n;
	int go = 0;
	while (1) {
		int a = ans;
		while (1) {
			if (a == 0) {
				go++;
				break;
			}
			int b = a % 10;
			if (abd.count(b))break;
			a /= 10;
		}
		if (go)break;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
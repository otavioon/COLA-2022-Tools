#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <set>
#define MAX 100000
#define rep(i,s,N) for(int i=s;i<N;i++)
using namespace std;
typedef long long int lli;

int main(void)
{
	int N; cin >> N;
	vector<string> s(N); rep(i, 0, N)cin >> s[i];
	int M; cin >> M;
	vector<string> t(M); rep(i, 0, M)cin >> t[i];
	set<string> say; rep(i, 0, N)say.insert(s[i]);
	set<string>::iterator li;
	int ans = 0;
	for (li = say.begin(); li != say.end(); li++) {
		int tmp_s = 0, tmp_t = 0;
		rep(i, 0, N)if (s[i] == *li)tmp_s++;
		rep(i, 0, M)if (t[i] == *li)tmp_t++;
		int tmp = max(tmp_s - tmp_t, 0);
		ans = max(ans, tmp);
	}
	cout << ans << endl;

	return 0;
}
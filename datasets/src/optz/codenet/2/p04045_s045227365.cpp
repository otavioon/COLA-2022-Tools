#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n, k; cin >> n >> k;
	
	vector<char> d(k); for (int i = 0; i < k; i++) cin >> d[i];
	
	int ans;
	for (int i = n; i <= 100000; i++) {

		string i_string = to_string(i);
		bool can = true;
		for (int j = 0; j < i_string.size(); j++) {
			for (int x = 0; x < k; x++) {				
				if (i_string[j] == d[x]) {
					can = false;
				}
			}
		}
		if (can) {
			ans = i;
			break;
		}

	}

	cout << ans << endl;	
	return 0;
}
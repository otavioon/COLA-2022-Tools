#include <iostream>
#include<algorithm>
#include <cstdio>

using namespace std;

int main()
{

	unsigned long long i, j, n, ans;
	unsigned long long *A = new unsigned long long[200002]();
	char *have = new char[1000000002]();
	unsigned long long twoTable[29] = { 4 };

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> A[i];
		have[A[i]]++;
	}
	
	for (i = 1; i < 29; i++) {
		twoTable[i] = twoTable[i - 1] * 2;
	}

	sort( &A[0] , &A[n + 1]);

	ans = 0;
	for (i = n; i > 0; i--) {
		if(have[A[i]]>0){
				for (j = 0; j < 29; j++) {
				if ((twoTable[j] > A[i]) && (twoTable[j]-A[i]<1000000001)) {
					int limit = 0;
					if (twoTable[j] == A[i] * 2) { limit = 1; }
					if (have[twoTable[j] - A[i]] > limit ) {
//						cout << twoTable[j] << " / " << A[i] << endl;
						have[twoTable[j] - A[i]]--;
						have[A[i]]--;
						ans++;
						j = 29;
					}
				}
			}
		}
	}


	delete have;
	delete A;

	cout << ans << endl;
	return 0;
}


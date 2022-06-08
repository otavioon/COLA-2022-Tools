#include <iostream>
#include<algorithm>
#include <cstdio>

using namespace std;

int main()
{

	unsigned long long i, j, n, ans;
	unsigned long long *A = new unsigned long long[200002]();
	bool *have = new bool[1000000002]();
	unsigned long long twoTable[29] = { 4 };

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> A[i];
		if (have[A[i]] == true) {
			have[111111111111111] = true;
		}
		have[A[i]] = true;
	}
	
	for (i = 1; i < 29; i++) {
		twoTable[i] = twoTable[i - 1] * 2;
	}

	sort( &A[0] , &A[n + 1]);

	ans = 0;
	for (i = n; i > 0; i--) {
		if(have[A[i]]==true){
				for (j = 0; j < 29; j++) {
				if ((twoTable[j] > A[i]) && (A[i] * 2 != twoTable[j]) && (twoTable[j]-A[i]<1000000001) ) {
					if (have[twoTable[j] - A[i]] == true) {
//						cout << twoTable[j] << " / " << A[i] << endl;
						have[twoTable[j] - A[i]] = false;
						have[A[i]] = false;
						ans++;
						j = 29;
					}
				}
			}
		}
	}


	delete have;

	cout << ans << endl;
	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define LMAX 1000

int L[LMAX+1];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		L[l]++;
	}
	;
	int cnt = 0;
	for (int i = 0; i <= LMAX; i++) {
		if (L[i] >= 3) {
			cnt++;
		}
		else if (L[i] == 2)
		{
			for (int j = 0; j <= LMAX; j++) {
				if (i == j)
					continue;
				if ((L[j] > 0) && (2 * i > j))
					cnt++;
			}
		}
		else if (L[i] == 1)
		{
			for (int j = i + 1; j <= LMAX; j++) {
				for (int k = j + 1; k <= LMAX; k++) {
					if (L[j] * L[k] == 0)
						continue;
					if (i + j > k)
						cnt++;
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
	
}
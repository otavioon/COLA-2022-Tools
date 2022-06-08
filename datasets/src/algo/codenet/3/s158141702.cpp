#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <iomanip>
#include <math.h> 



using namespace std;

int main() {
	int  i, j, k, n;
	int a[100001] = { 0 }, b[100001] = { 0 }, c[100001] = { 0 };

	cin >> n;

	
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (i = 0; i < n; i++) {
		cin >> c[i];
	}

	sort(a, a + 100001);
	sort(b, b + 100001);
	sort(c, c + 100001);

	for (i = 0; i < 100; i++) {
		//cout << a[i] << " ";
	}

	int cnt = 0;
	for (i = 0; i < 100001; i++) {
		if (a[i] == 0) continue;
		for (j = 0; j < 100001; j++) {
			if (b[j]==0 || a[i] >= b[j]) {
				continue;
			}
			for (k = 0; k < 100001; k++) {
				if (c[k] <= b[j]) continue;
				cnt++;
			}
		}
	}
	
	cout << cnt << endl;




	return 0;
}
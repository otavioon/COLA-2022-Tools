#include<iostream>
#include<string>
#include<algorithm>
#include <map>  
#include <string.h>
#include <math.h>

using namespace std;

int n, f1, f2, fs1=0, fs2=0, sum =0;
int A[100001], B[100001], C[100001];

int lo(int a) {
	for (int i = f2; i >= 1; i--) {
		if (B[a] < C[i]) {
			fs2++;
			f2 = i - 1;
		}
		else break;
	}
	return fs2;
}

int up(int a) {
	for (int i = f1; i >= 1; i--) {
		if (A[a] < B[i]) {
			fs1 += lo(i);
			f1 = i - 1;	
		}
		else break;
	}
	return fs1;
}

int main()
{

	cin >> n;
	f1 = n;
	f2 = n;

	for (int i = 0; i < n; i++)cin >> A[i + 1];
	for (int i = 0; i < n; i++)cin >> B[i + 1];
	for (int i = 0; i < n; i++)cin >> C[i + 1];
	sort(A, A + (n + 1));
	sort(B, B + (n + 1));
	sort(C, C + (n + 1));

	for (int i = n; i >= 1; i--) sum += up(i);

	cout << sum << endl;

	return 0;
}
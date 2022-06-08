#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<time.h>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector <int>A(N);
	vector <int>B(N);
	vector <int>C(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	int count1 = 0, count2 = 0;
	for (int i = 0; i < N; i++) {
		for (int m = 0; m < N; m++) {
			if (A[i] < B[m])count1++;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int m = 0; m < N; m++) {
			if (B[i] < C[m])count2++;
		}
	}
	cout << count1 * count2;
	return 0;
}
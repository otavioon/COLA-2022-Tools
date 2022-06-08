#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
#include<stdio.h>
using namespace std;
 
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define INF 1<<25

int A[100001];
int B[100001];
int C[100001];
int abc[100001] = {};
int main()
{	
	int i, j, k;
	int n;
	cin >> n;
	rep(i, n) cin >> A[i];
	rep(i, n) cin >> B[i];
	rep(i, n) cin >> C[i];
	sort(A, A + n);
	sort(B, B + n);
	sort(C, C + n);
	int count = 0;
	rep(i, n) {
		int t_b = B[i];
		rep(j, n) {
			int t_c = C[j];
			if (t_b < t_c) {
				abc[i]++;
			} else {
				continue;
			}
		}
	}
	rep(i, n) {
		rep(j, n) {
			if (A[i] < B[j]) {
				count += abc[j];
			} else {
				continue;
			}
		}
	}
	cout << count << endl;
	return 0;
}
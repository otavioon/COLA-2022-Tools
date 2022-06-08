#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;
int digit(int n){
		int count = 0; 
		while(n > 0){
			n /= 2; 
			count ++; 
		}
		return count; 
	}
int main(){
	int N; 
	cin >> N; 
	int A[200010] = {}; 
	for(int i = 0; i < N; i++){
		cin >> A[i]; 
	}
	int D[200010] = {}; 
	for(int i = 0; i < N; i++){
		D[i] = digit(A[i]);  
	}
	sort(A, A+N, greater<int>()); 
	int B[200010] = {}; 
	for(int i = 0; i < N; i++){
		B[i] = (1 << digit(A[i])) - A[i]; 
	}
	int count = 0; 
	int r = N - 1; 
	for(int i = 0; i < N; i++){
		for(int j = r; j >= 0; j--){
			if((B[i] == A[j] && B[i] > 0) && i != j){count ++; A[i] = -1, A[j] = -1; B[i] = -1; B[j] = -1; r = max(j-1, 0); break;}
			if(B[i] > 0 && A[j] > 0 && B[i] < A[j]){r = min(j+1, N-1); break;}
		}
		if((i != (N - 1)) && D[i] != D[i+1]) {r = N - 1;}
	}
	cout << count << endl; 
}
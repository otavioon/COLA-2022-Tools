#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 100005

ll N;
ll A[NUM],B[NUM],C[NUM];
ll rui_B[NUM];

int main(){

	scanf("%lld",&N);

	for(int i = 0; i < N; i++){

		scanf("%lld",&A[i]);
	}

	for(int i = 0; i < N; i++){

		scanf("%lld",&B[i]);
	}

	for(int i = 0; i < N; i++){

		scanf("%lld",&C[i]);
	}

	sort(A,A+N);
	sort(B,B+N);
	sort(C,C+N);

	for(int i = 0; i <= N; i++){

		rui_B[i] = 0;
	}

	//Bより多いCの数を数える
	int index = N-1;

	for(int loc = N-1; loc >= 0; loc--){

		while(index >= 0 && C[index] > B[loc])index--;

		rui_B[loc] = N-(index+1);
		rui_B[loc] += rui_B[loc+1];
	}

	ll ans = 0;

	index = N-1;

	for(int loc = N-1; loc >= 0; loc--){

		while(index >= 0 && B[index] > A[loc])index--;

		ans += rui_B[index+1];
	}

	printf("%lld\n",ans);

	return 0;
}

#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 200005


int N,K;
double A[SIZE];

bool isOK(double len){

    ll ret = 0;
	for(int i = 0; i < N; i++){

		ret += (ll)ceil(A[i]/len)-1;
	}

	return ret <= K;
}

int main(){

	scanf("%d %d",&N,&K);

	double maximum = 0;

	for(int i = 0; i < N; i++){

		scanf("%lf",&A[i]);
		maximum = max(maximum,A[i]);
	}

	double left = 0,right = maximum,mid = (left+right)/2;
	double ans = maximum;

	for(int loop = 0; loop < 100; loop++){

		if(isOK(mid)){

			ans = mid;
			right = mid-EPS;
		}else{

			left = mid+EPS;
		}
		mid = (left+right)/2.0;
	}

	printf("%.0lf\n",ceil(ans));

	return 0;
}

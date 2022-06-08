#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

#define INF 1000000000

using namespace std;

int main()
{
	int n;
	long long int a, b;
	long long int h[100000];
	long long int hs[100000];

	scanf("%d %lld %lld", &n, &a, &b);
	for(int i=0; i<n; i++){
		scanf("%lld", &h[i]);
	}
	sort(h, h+n);
	for(int i=n-1; i>=0; i--){
		if(i==n-1){
			hs[n-1]=h[n-1];
		}else{
			hs[i]=hs[i+1]+h[i];
		}
	}
	
	int m=0;
	while(m<n){
		if(h[m]<=(hs[m]*b)/(a-b+(n-m)*b)){
			m++;
		}else{
			break;
		}
	}

	long long int x0, x1, x2,x;
	if(hs[m]%(a-b+(n-m)*b)==0){
		x0=hs[m]/(a-b+(n-m)*b);
	}else{
		x0=hs[m]/(a-b+(n-m)*b)+1;
	}

	x1=x0;
	x2=x0+n-m+1;

	while(x1!=x2){
		long long int sum=0;
		x=(x1+x2)/2;
		for(int i=m; i<n; i++){
			if(h[i]-x*b>=0 && (h[i]-x*b)%(a-b)==0){
				sum=sum+(h[i]-x*b)/(a-b);
			}else if(h[i]-x*b>=0){
				sum=sum+(h[i]-x*b)/(a-b)+1;
			}
		}
		if(x>=sum){
			x2=x;
		}else{
			x1=x+1;
		}
	}

	long long int x3;
	if(m==0){
		x3=0;
	}else if(h[m-1]%b==0){
		x3=h[m-1]/b;
	}else{
		x3=h[m-1]/b+1;
	}

	if(x1<x3){
		x=x3;
	}else{
		x=x1;
	}

	printf("%lld\n", x);

	return 0;

}
	#include <cstdio>
	#include <string>
	#include <iostream>
	#include <algorithm>
	#include <cmath>

	using namespace std;
	using ll=long long int;
	int n,k;
	int d[10];

	int main(){
		scanf("%d %d",&n,&k);
		for(int i=0;i<10;i++) d[i]=1;
		for(int i=0;i<k;i++) {
			int k;
			scanf("%d",&k);
			d[k]=0;
		}
		int mn;
		for(int i=10;i>=0;i--) if(d[i]) mn=i;
		while(true){
			int k=n;
			if(!d[(k/10000)%10])n=n+10000-n%10000;
			if(!d[(k/1000)%10])n=n+1000-n%1000;
			else if(!d[(k/100)%10])n=n+100-n%100;
			else if(!d[(k/10)%10])n=n+10-n%10;
			else if(!d[(k/1)%10])n=n+1;
			else break;
		}
		printf("%d",n);
		return 0;
	}
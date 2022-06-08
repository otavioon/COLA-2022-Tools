#include<bits/stdc++.h>
using namespace std;
long long n,mx,pow_10[15];
int main(){
	scanf("%lld",&n);
	for(int i=sqrt(n);i>=1;i--){
		if(n%i==0){
			mx=n/i;
			break;
		}
	}
	pow_10[0]=1;
	for(int i=1;i<=10;i++){
		pow_10[i]=pow_10[i-1]*10;
	}
	for(int i=1;i<=10;i++){
		if(mx>=pow_10[i-1]&&mx<pow_10[i]){
			printf("%lld",i);
			break;
		}
	}
}
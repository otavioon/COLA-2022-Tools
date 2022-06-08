#include<bits/stdc++.h>
using namespace std;
char s[1002],p;
long long a,n,b,k,l,r;
int main(){
	cin>>s;
	cin>>n;
	if(s[0]==s[strlen(s)-1]){
		l=0;
		while(s[++l]==s[0]);
		r=strlen(s)-1;
		while(s[--r]==s[strlen(s)-1]);
		for(long long i=1;i<strlen(s);++i){
			if(s[i]==s[i-1]){
				k++;
				i++;
			}
		}
		if(l>r){
			if(strlen(s)%2==0){
				printf("%lld",k*n);
			}
			else{
				printf("%lld",k*n+n/2);
			}
		}
		else{
			for(register int i=l+1;i<=r;++i){
				if(s[i]==s[i-1]){
					b++;
					i++;
				}
			}
			printf("%lld",k+(b+(l+strlen(s)-1-r)/2)*(n-1));
		}

	}
	else{
		for(long long i=1;i<strlen(s);++i){
			if(s[i]==s[i-1]){
				k++;
				i++;
			}
		}
		printf("%lld",k*n);
	}
}
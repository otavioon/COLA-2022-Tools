#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=110;
char s[N]; LL k,len;
int main(){
	scanf("%s%lld",s,&k); len=strlen(s);
	bool flag=0;
	for(LL i=1; i<len; ++i)
		if(s[i]!=s[i-1])flag=1;
	if(!flag)return printf("%lld",len*k/2),0;
	if(s[len-1]!=s[0]){
		LL ans=0;
		for(LL i=0; i<len; ){
			LL j=i;
			while(j<len&&s[j]==s[i])++j;
			ans+=(j-i)/2;
			i=j;
		}
		printf("%lld",ans*k);
	}else{
		LL ans=0;
		LL len1,len2;
		for(len1=0; s[len1]==s[0]; ++len1);
		for(len2=len-1; s[len2]==s[len-1]; --len2);
		for(LL i=len1; i<=len2;){
			LL j=i;
			while(j<=len2&&s[j]==s[i])++j;
			ans+=(j-i)/2;
			i=j;
		}
		printf("%lld",ans*k+(len1+len-len2-1)/2*(k-1)+len1/2+(len-len2-1)/2);
	}
	return 0;
}
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100010;
char s[N];
int k,t[N],a,b;
int main(){
	scanf("%s%d",s+1,&k);
	int n=strlen(s+1);
	bool all=1;
	for(int i=1;i<=n;i++)if(s[i]!=s[1])all=0;
	if(all){
		LL ans=(LL)n*k/2;
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]!=s[1]){
			a=i-1;break;
		}
	}
	for(int i=n;i>=1;i--){
		if(s[i]!=s[n]){
			b=n-i;break;
		}
	}
	int tot=0;
	
	for(int i=a+1;i<=n-b;i++){
		if(s[i]!=s[i-1]){
			t[i]=1;
		}
		else{
			t[i]=t[i-1]+1;
			if(t[i]%2==0)tot++;
		}
	}
	LL ans=0;
	if(s[1]==s[n]){
		ans=(LL)tot*k+a/2+b/2+(LL)(a+b)/2*(k-1);
	}
	else{
		ans=(LL)tot*k+(LL)a/2*k+(LL)b/2*k;
	}
	cout<<ans<<endl;
}
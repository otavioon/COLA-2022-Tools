#include<bits/stdc++.h>
using namespace std;
#define int long long
int K,ans;
char s[105];
signed main(){
	scanf("%s",s+1);
	scanf("%lld",&K);
	int k=1,n=strlen(s+1);
	if (s[1]==s[n]){
		while (k<=n&&s[1]==s[k])k++;
		if (k>n){
			printf("%lld\n",n*K/2);
			return 0;
		}
		n--;int p=n+1;
		while (s[n]==s[p])n--;
		ans+=(p-n+k-1)/2*(K-1);
		ans+=(p-n)/2+(k-1)/2;
	}
	for (int i=k,j=1;i<=n;i=j){
		while (s[i]==s[j])j++;
		ans+=(j-i)/2*K;
	}
	printf("%lld\n",ans);
}
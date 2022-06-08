#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,tot,res,tmp,ck[100005],sum[100005];
long long ans;
char s[10000005];
int main(){
	scanf("%s%d",s,&k);
	n=strlen(s);
	for(int i=n;i<n*100000;i++){
		s[i]=s[i%n];
	}
	memset(ck,-1,sizeof(ck));
	for(int i=0;i<100000;i++){
		for(int j=i*n;j<(i+1)*n;j++){
			if(s[j]==s[j-1]){
				s[j]='a';
				while((!j||s[j]==s[j-1])||s[j]==s[j+1]){
					s[j]++;
				}
				tot++;
			}
		}
		sum[i]=tot;
		if(ck[(int)s[(i+1)*n-1]]!=-1){
			tmp=ck[(int)s[(i+1)*n-1]];
			res=i;
			break;
		}
		ck[(int)s[(i+1)*n-1]]=i;
	}
	ans=sum[tmp];
	k-=tmp+1;
	ans+=1LL*(sum[res]-sum[tmp])*k/(res-tmp);
	k%=(res-tmp);
	ans+=sum[tmp+k+1]-sum[tmp+1];
	printf("%lld\n",ans);
	return 0;
}
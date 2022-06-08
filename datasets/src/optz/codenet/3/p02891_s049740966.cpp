#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=1e5+5,mo=998244353;
int n,k;
char a[N];
ll ans;
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
int main(){
	scanf("%s",a+1);
	cin>>k;
	n=strlen(a+1);
	int is=1;
	fo(i,2,n)if(a[i]!=a[1]){
		is=0;break;
	}
	if(is)ans=(ll)n*k/2;else{
		int st=0,en=0,ss=0;
		fo(i,1,n){
			++ss;
			if(i==n||a[i]!=a[i+1]){
				if(ss==i){
					st=ss;ss=0;continue;
				}
				if(i==n){
					en=ss;continue;
				}
				ans+=ss/2;
				ss=0;
			}
		}
		ans=ans*k;
		if(a[1]==a[n])ans+=st/2+en/2+(ll)(st+en)/2*(k-1);
		else ans+=(ll)(st/2+en/2)*k;
	}
	cout<<ans;
}
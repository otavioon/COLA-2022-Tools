#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

char s[105];
ll n,K,ans;

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	read(K);
	int pre=1;
	while(pre<n&&s[pre]==s[pre+1]) pre++;
	int suf=n;
	while(suf>1&&s[suf]==s[suf-1]) suf--;
	if(pre==n){
		cout<<n*K/2<<endl;
		return 0;
	}
	ans+=pre/2+(n+1-suf)/2;
	if(s[1]==s[n]){
		ans+=(pre+n+1-suf)/2*(K-1);
	}
	else{
		ans+=(pre/2+(n+1-suf)/2)*(K-1);
	}
	rep(i,pre+1,suf-1){
		int c=1;
		while(i+1<=suf-1&&s[i]==s[i+1]){
			c++,i++;
		}
		ans+=c/2*K;
	}
	cout<<ans<<endl;
	return 0;
}
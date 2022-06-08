#include<cstdio>
#include<cctype>
#include<algorithm>
const int maxn=200010,inf=0x7fffffff;
int n;
int a[maxn];
bool v[maxn];
int ans;
int In() {
    register char c;
    for(;c=getchar(),c!='-'&&!isdigit(c););
    register bool f=c=='-';
    register int s=f?0:c-'0';
    for(;c=getchar(),isdigit(c);)s=s*10+c-'0';
    return f?-s:s;
}
int main() {
	n=In();
	for(register int i=1;i<=n;++i)a[i]=In();
	std::sort(a+1,a+n+1);
	for(register int i=30;i;--i) {
		register int l=1,r=n;
		for(register int p=1<<i;l<r;--r) {
			for(;l<r&&v[r];--r);
			for(;l<r&&a[l]+a[r]<p;++l);
			for(;l<r&&v[l];++l);
			if(l>=r) break;
			if(a[l]+a[r]==p) v[l]=v[r]=1,++ans,++l;
		}
	}
	printf("%d\n",ans);
	return 0;
}
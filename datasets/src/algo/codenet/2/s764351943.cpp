#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int read() {
	char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	int x=ch-'0';
	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

const int N=2e5+5;

int n,a[N],ans;
bool used[N];

int main() {
	n=read();
	fo(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	int ans=0;
	fd(s,30,1) {
		int x=1<<s;
		int j=n;
		fo(i,1,n) 
			if (!used[i]) {
				while (j>i&&a[j]>x-a[i]||used[j]) j--;
				if (i==j) break;
				if (a[j]==x-a[i]) used[i]=used[j]=1,ans++;
			}
	}
	printf("%d\n",ans);
	return 0;
}
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<algorithm>
#define ri(x) scanf("%d",&x)
#define rl(x) scanf("%I64d",&x)
#define pi(x) printf("%d",&x)
#define pl(x) printf("%I64d",&x)
#define lfd() printf("\n")
#define sp() printf(" ")
#define inrep(x) int x;scanf("%d",&x);while(x--)
using namespace std;
int n;
int a[100100],b[100100],c[100100];
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	long long res=0;
	int numa=0,numc=0;
	c[n+1]=2e9;
	for(int i=1;i<=n;i++){
		while(a[numa]<b[i]&&numa<=n) numa++;
		while(c[numc]<=b[i]&&numc<=n) numc++;
		res+=(long long)(numa-1)*(long long)(n-numc+1);
	}
	cout<<res<<endl;
	return 0;
}

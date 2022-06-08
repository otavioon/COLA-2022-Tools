#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct cmp{
	bool operator () (const int &a,const int &b)
	{return a>b;}
};
multiset<int,cmp> s;
int n,a[N],ans;
int lowbit(int x){return x&(-x);}
int count(int x)
{
	int res=0;
	while (x) x/=2,res++;
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),s.insert(a[i]);
	while (s.size()>1)
	{
		int t=*s.begin();s.erase(s.begin());
		int p=lowbit(t),cnt=count(t);
		int x=(((1<<cnt)-1)^t)/p*p+p;
		if (s.find(x)!=s.end()) s.erase(s.find(x)),ans++;
	}
	printf("%d\n",ans);
	return 0;
}
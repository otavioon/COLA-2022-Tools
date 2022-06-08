#include<bits/stdc++.h>
#define fre(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
using namespace std;
int n,ans;
multiset<int>st;
int main()
{
//	fre(powers);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		st.insert(x);
	}
	while(!st.empty())
	{
		multiset<int>::iterator it=st.end();
		it--;
		int x=*it;
		st.erase(it);
		int y=1;
		while(y<=x) y<<=1;
		if(st.find(y-x)!=st.end())
		{
			st.erase(st.find(y-x));
			ans++;
		}
	}
	printf("%d\n",ans);
}
/*
4
3 5 11 13
*/
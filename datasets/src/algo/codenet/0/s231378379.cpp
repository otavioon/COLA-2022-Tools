#include<bits/stdc++.h>
using namespace std;
string s;int k;
int main()
{
	cin>>s>>k;
	bool flag=1;
	for(int i=0;i<(int)s.size();i++) if(s[i]!=s[0]) flag=0;
	if(flag) return printf("%lld\n",1ll*s.size()*k/2),0;
	long long ans=0;
	if(s[0]==s[s.size()-1])
	{
		int l=0,r=s.size()-1;
		while(s[l+1]==s[l]) l++;
		while(s[r-1]==s[r]) r--;
		int lcnt=l+1,rcnt=s.size()-r;
		ans+=lcnt/2+rcnt/2+1ll*(lcnt+rcnt)/2*(k-1);
		string t="";
		for(int i=l+1;i<r;i++) t+=s[i];
		s=t;
	}
	int cnt=0;
	for(int i=0;i<(int)s.size();i++)
	{
		cnt++;
		if(i+1==(int)s.size()||s[i+1]!=s[i])
		{
			ans+=1ll*cnt/2*k;
			cnt=0;
		}
	}
	cout<<ans<<endl;
}
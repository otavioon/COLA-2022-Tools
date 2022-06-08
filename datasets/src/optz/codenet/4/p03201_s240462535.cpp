#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int n,i,j,a[200005],ans;
set<pair<int,int> > s;
int read(){
	char ch=getchar();
	int xx=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return xx;
}
int main(){
	n=read();
	set<pair<int,int> > :: iterator it;
	for(i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);	
	for(i=1;i<=n;i++)
		s.insert(make_pair(a[i],i));
	for(i=n;i>=1;i--){
		it=s.lower_bound(make_pair(a[i],i));
		if(it->second==i)
			s.erase(make_pair(a[i],i));
		for(j=1;j<=a[i];j<<=1);
		it=s.lower_bound(make_pair(j-a[i],0));
		if(it->first==j-a[i]){
			ans++;
			s.erase(make_pair(it->first,it->second));
		}
	}
	cout<<ans<<endl;
	return 0;
}
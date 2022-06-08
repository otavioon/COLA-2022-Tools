#include<bits/stdc++.h>
#define intt long long 
using namespace std;
int read(){int k;scanf("%d",&k);return k;}
multiset<intt>S;
multiset<intt>::iterator it,it1;
intt flag=0,ans,n,x;
int main(){	
	n=read();
	for(int i=1;i<=n;i++)x=read(),S.insert(x);
	while(!S.empty()){	
		it=S.end();it--;
		flag=0;
		S.erase(it);
		for(int i=1;i<=31;i++){	
			intt v=(1<<i)-*it;
			it1=S.find(v);
			if(it1==S.end())continue;
			flag=1;
			S.erase(it1);ans++;
		}	
	}		
	cout<<ans<<endl;
	return 0;
}	
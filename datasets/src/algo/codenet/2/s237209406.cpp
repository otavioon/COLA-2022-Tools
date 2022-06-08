#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,i; 
	multiset<int,greater<int> > a;
	multiset<int,greater<int> >::iterator it;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x;
		a.insert(x);
	}
	int ans=0;
	while(!a.empty()){
		it=a.begin();
		x=*it;
		int y=1;
		while(y<x)y*=2;
		a.erase(x);
		it=a.find(y-x);
		if(it!=a.end()){
			ans++;
			a.erase(it);
		}
	}
	cout<<ans<<endl;
	return 0;
}

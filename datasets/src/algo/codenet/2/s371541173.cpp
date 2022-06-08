#include<bits/stdc++.h>
using namespace std;

multiset <int> Set;
int n,ans=0;

int getpow(int x){
	int ret=1;
	while(ret<=x) ret+=ret;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		Set.insert(x);
	}
	while(!Set.empty()){
		multiset <int> :: iterator it=Set.end();
		it--;
		int x=*it;
		int i=getpow(x);
		Set.erase(Set.find(x));
		if(Set.find(i-x)!=Set.end()){
			Set.erase(Set.find(i-x));
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
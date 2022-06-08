#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

multiset <ll> Set;
int n;
int ans=0;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		Set.insert(x);
	}
	while(!Set.empty()){
		multiset <ll>::iterator it=Set.end();
		it--;
		int x=*it;
		Set.erase(x);
		int i;
		for(i=1;i<=x;i*=2);
		if(Set.find(i-x)!=Set.end()){
			Set.erase(Set.find(i-x));
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
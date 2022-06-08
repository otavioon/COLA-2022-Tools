#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	multiset<int,greater<int> > M;
	for(int i=1,x;i<=n;i++)
		cin>>x,M.insert(x);
	int ans = 0;
	while(M.size()){
		int x = *M.begin();
		M.erase(M.begin());
		int y = (1<<(32-__builtin_clz(x)))-x;
		if(M.count(y)){
			ans++;
			M.erase(M.find(y));
		}
	}
	cout<<ans<<endl;
}

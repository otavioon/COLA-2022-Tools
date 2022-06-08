#include<iostream>
#include<set>
using namespace std;
int n;
multiset<int>s;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		s.insert(x);
	}
	int ans=0;
	while(!s.empty()){
		multiset<int>::iterator it=s.end();
		--it;
		int cur=*it;
		s.erase(it);
		for(int i=30; i>=0 ;i--){
			auto it2=s.lower_bound((1<<i)-cur);
			if(it2!=s.end() && *it2==(1<<i)-cur){
				ans++;
				s.erase(it2);
				break;
			}
		}
	}
	cout << ans << endl;
}
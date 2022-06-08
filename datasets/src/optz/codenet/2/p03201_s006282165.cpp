#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> a(n);
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	int ans=0;
	
	for(auto it=mp.rbegin();it!=mp.rend();it++){
		auto x = it->first, y=it->second;
		
		int nx = log2(x);
		if((1<<nx)==x){
			ans+=y/2;
		}
		else{
			nx++;
			int req = (1<<nx)-x;
			if(mp.find(req)!=mp.end()){
				int avail = min(mp[req], y);
				ans+= avail;
				mp[req]-= avail;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)

using namespace std;

int main() {
	int n; cin>>n;
	vector<int>v;

	for(int i=0;i<n;i++){
		int h; cin>>h;
		h--;
		v.push_back(h); }

	int now=0,c=0;
	for(int i=0;i<n;i++)
   {
		if(now==1){
			cout<<c<<endl;
			return 0; }
		c++;
		now=v[now];
	}

	cout<<-1<<endl;

	return 0;
}

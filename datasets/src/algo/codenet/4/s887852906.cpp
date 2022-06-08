// RAM RAM

#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define mp make_pair
using namespace std;


set<int> v;
bool hai(int n){
	if(v.find(n)!=v.end()){
		return false;
	}
	return true;
}

bool valid(int n){
	while(n){
		if(!(hai(n%10))){
			return false;
		}
		n/=10;
	}
	return true;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	
	int n,k;cin>>n>>k;
	for(int i=0;i<k;i++){
		int temp;cin>>temp;
		v.insert(temp);
	}

	for(int i=n;;i++){
		if(valid(i)){
			cout<<i<<endl;
			break;
		}
	}
}
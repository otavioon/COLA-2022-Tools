#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

string n; int k;
set<int> d;
ll mod = 1e9+7;

ll fpow(ll a, ll b, ll md){
	ll res = 1;
	a = (a%md);
	while(b>0){
		if(b%2==1){
			res = (res*a)%md;
		}
		b = b/2;
		a = (a*a)%md;
	}
	return res%md;
}

int f(int i, int num){
	if(i >= n.size()+1){
		// if(num==9999) cout<<"here"<<endl;
		if(num >= stoi(n)){
			return num-stoi(n);
		}
		else{
			return INT_MAX;
		}
	}

	int ans = INT_MAX;
	for(int j=0;j<10;j++){
		if(d.count(j)) continue;
		ans = min(ans, f(i+1,num+ j*fpow(10,i,mod)));
	}
	if(i==n.size()){
		ans = min(ans, f(i+1,num));
	}
	return ans;
}

int main(){
	fastread;
	cin>>n>>k;
	for(int i=0;i<k;i++){
		int u;
		cin>>u;
		d.insert(u);
	}
	int dif = f(0,0);
	// cout<<dif<<endl;
	cout<<stoi(n)+dif<<endl;




	return 0;
}

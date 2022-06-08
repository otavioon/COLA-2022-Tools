#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

vector<bool> D(10,true);

bool dec(int n){
	while(n>0){
		if(!D.at(n%10)) return false;
		n/=10;
	}
	return true;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,k;cin >> n >> k;
	rep(i,k){
		int a;
		cin >> a;
		D.at(a)=false;
	}
	int i=n;
	while(true){
		if(dec(i)){
			cout << i << endl;
			return 0;
		}
		i++;
	}
}